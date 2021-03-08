#include "plotter.h"

Plotter::Plotter(QWidget *parent) :
    QWidget(parent)
{
    setBackgroundRole(QPalette::Dark);//使用调色板中的"暗"分量作为重绘窗口部件的背景颜色
    setAutoFillBackground(true);//打开自动填充背景将setBackgroundRole启用
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);//允许横纵方向的放大或者缩小
    setFocusPolicy(Qt::StrongFocus);//通过单击或者Tab键入焦点

    zoomInButton = new QToolButton(this);
    zoomInButton->setIcon(QIcon(":/images/zoomin.png"));
    zoomInButton->adjustSize();//设置成大小提示给定的大小
    connect(zoomInButton, SIGNAL(clicked()), this, SLOT(zoomIn()));

    zoomOutButton = new QToolButton(this);
    zoomOutButton->setIcon(QIcon(":/images/zoomout.png"));
    zoomOutButton->adjustSize();
    connect(zoomOutButton, SIGNAL(clicked()), this, SLOT(zoomOut()));

    setPlotSettings(PlotSettings());
}
//共有槽函数部分
/*
 *  初始化缩放堆栈(用户没进行一次放大就在缩放堆栈中存储一个新的实例)
*/
void Plotter::setPlotSettings(const PlotSettings &settings)
{
    zoomStack.clear();
    zoomStack.append(settings);
    curZoom = 0;
    zoomInButton->hide();
    zoomOutButton->hide();
    refreshPixmap();
}
void Plotter::zoomOut()//缩小
{
    if(curZoom > 0)
    {
        curZoom--;
        zoomOutButton->setEnabled(curZoom > 0);
        zoomInButton->setEnabled(true);
        zoomInButton->show();
        refreshPixmap();
    }
}
void Plotter::zoomIn()//放大
{
    if(curZoom < zoomStack.count() - 1)
    {
        curZoom++;
        zoomInButton->setEnabled(curZoom < zoomStack.count() - 1);
        zoomOutButton->setEnabled(true);
        zoomOutButton->show();
        refreshPixmap();
    }
}
/*
 *  功能:设置了用于给定曲线ID中的数据,一条曲线的ID与curveMap中已经
 *       存在的ID相同,那么将会用新的曲线代替旧的曲线,如果不同则插入一条新的曲线
*/
void Plotter::setCurveData(int id, const QVector<QPointF> &data)
{
    curveMap[id] = data;
    refreshPixmap();
}
void Plotter::clearCurve(int id)
{
    curveMap.remove(id);
    refreshPixmap();
}
QSize Plotter::minimumSizeHint() const//指定一个窗口部件理想的最小大小
{
    return QSize(6 * Margin, 4*Margin);
}
QSize Plotter::sizeHint() const
{
    return QSize(12 * Margin, 8 * Margin);
}

//事件处理部分
void Plotter::paintEvent(QPaintEvent *)
{
    QStylePainter painter(this);//申请一个带有当前系统风格的画笔
    painter.drawPixmap(0, 0, pixmap);//在坐标0,0处开始绘制pixmap

    if(rubberBandIsShown)//自由选择框可见
    {
        painter.setPen(palette().light().color());//画笔选用调色板中的亮色
        painter.drawRect(rubberBandRect.normalized().adjusted(0, 0, -1, -1));
        //绘制矩形rubberBandRect,normalized返回矩形范围如果长宽为负值则交换底部和顶部的长度,adjusted调整矩形坐标移动以及大小
    }
    if(hasFocus())//Plotter拥有焦点
    {
        QStyleOptionFocusRect option;//拥有当前系统风格的焦点矩形
        option.initFrom(this);//初始化焦点矩形的各个绘制选项
        option.backgroundColor = palette().dark().color();//焦点矩形背景选用调色板暗色
        painter.drawPrimitive(QStyle::PE_FrameFocusRect, option);
        //实际上调用了QStyle类中的同名函数
    }
}
/*
 *  一旦改变窗口部件的大小,就会产生一个重定义大小事件
*/
void Plotter::resizeEvent(QResizeEvent *)//重定义大小事件
{
    int x = width() - (zoomInButton->width()
                       + zoomOutButton->width() + 10);
    zoomInButton->move(x, 5);
    zoomOutButton->move(x + zoomInButton->width() + 5, 5);
    refreshPixmap();
}
void Plotter::mousePressEvent(QMouseEvent *event)
{
    QRect rect(Margin, Margin, width() - 2 * Margin,
               height() - 2 * Margin);

    if(event->button() == Qt::LeftButton)
    {
        if(rect.contains(event->pos()))
        {
            rubberBandIsShown = true;
            qDebug()<<event->pos();
            rubberBandRect.setTopLeft(event->pos());//设置矩形左上角坐标.可以改变大小但不会改变矩形右下角
            rubberBandRect.setBottomRight(event->pos());//设置矩形右下角坐标.可以改变大小但不会改变矩形左下角
            updateRubberBandRegion();//对自由选择框覆盖的区域进行强制重绘
            setCursor(Qt::CrossCursor);//改变鼠标形态
        }
    }
}
void Plotter::mouseMoveEvent(QMouseEvent *event)
{
    if(rubberBandIsShown)
    {
        updateRubberBandRegion();
        rubberBandRect.setBottomRight(event->pos());
        updateRubberBandRegion();
    }
}
void Plotter::mouseReleaseEvent(QMouseEvent *event)//自由选择框放大图像的核心函数
{
    if((event->button() == Qt::LeftButton) && rubberBandIsShown)
    {
        rubberBandIsShown = false;
        updateRubberBandRegion();//擦除自由选择框
        unsetCursor();//撤销鼠标的图标设置

        QRect rect = rubberBandRect.normalized();
        if(rect.width() < 4 || rect.height() < 4)
            return;
        rect.translate(-Margin, -Margin);//平移矩形

        PlotSettings prevSettings = zoomStack[curZoom];
        PlotSettings settings;
        /*原图像x轴范围 / 原图像的的宽度 = x轴每个像素的长度(一个像素为dx个刻度)*/
        double dx = prevSettings.spanX() / (width() - 2 * Margin);
        double dy = prevSettings.spanY() / (height() - 2 * Margin);
        settings.minX = prevSettings.minX + dx * rect.left();//自选框左边对应像素坐标*单位像素刻度+原图像x轴最小值 = 放大图像x轴最小值
        settings.maxX = prevSettings.minX + dx * rect.right();
        settings.minY = prevSettings.maxY -dy * rect.bottom();
        settings.maxY = prevSettings.maxY - dy * rect.top();
        settings.adjust();//圆整数据,为每根坐标轴找出一个合适的刻度标记符个数(数据秒点核心算法)

        zoomStack.resize(curZoom + 1);//栈中增加一个缩放量级
        zoomStack.append(settings);//将最新的缩放级追加进栈中
        zoomIn();//进行放大
    }
}
void Plotter::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Plus:
        zoomIn();
        break;
    case Qt::Key_Minus:
        zoomOut();
        break;
    case Qt::Key_Left:
        zoomStack[curZoom].scroll(-1, 0);
        refreshPixmap();
        break;
    case Qt::Key_Right:
        zoomStack[curZoom].scroll(+1, 0);
        refreshPixmap();
        break;
    case Qt::Key_Down:
        zoomStack[curZoom].scroll(0, -1);
        refreshPixmap();
        break;
    case Qt::Key_Up:
        zoomStack[curZoom].scroll(0, +1);
        refreshPixmap();
        break;
    default:
        QWidget::keyPressEvent(event);//为保证其他默认的快捷键不被忽略
    }
}
void Plotter::wheelEvent(QWheelEvent *event)
{
    int numDegrees = event->delta() / 8;//delta返回滚动旋转角度的8倍
    int numTicks = numDegrees / 15;//滚轮通常以15度为步长

    if(event->orientation() == Qt::Horizontal)
    {
        zoomStack[curZoom].scroll(numTicks, 0);//垂直滚轮
    }
    else
    {
        zoomStack[curZoom].scroll(0, numTicks);//水平滚轮(部分鼠标有水平滚轮)
    }
    refreshPixmap();
}
void Plotter::updateRubberBandRegion()//自由选择框四条宽度为1像素的边构成,因此需要四个指定范围的update函数来更新
{
    QRect rect = rubberBandRect.normalized();
    update(rect.left(), rect.top(), rect.width(), 1);//上边界
    update(rect.left(), rect.top(), 1, rect.height());//左边界
    update(rect.left(), rect.bottom(), rect.width(), 1);//下边界
    update(rect.right(), rect.top(), 1, rect.height());//右边界
}
/*
 *  功能将绘图区重新绘制到脱屏像素映射上,并且对显示加以更新
*/
void Plotter::refreshPixmap()
{
    pixmap = QPixmap(size());//将窗口部件大小存储在脱屏像素上
    pixmap.fill(this, 0, 0);//使用擦除颜色填充像素映射,如果小部件的背景色不是全填充的就要指定偏移量

    QPainter painter(&pixmap);//创建一个painter 在pixmap上进行绘制
    painter.initFrom(this);//初始化画笔, 背景色, 字体与Plotter一致
    drawGrid(&painter);//绘制网格
    drawCurves(&painter);//绘制顶点
    update();
}
void Plotter::drawGrid(QPainter *painter)
{
    QRect rect(Margin, Margin,
               width() - 2 * Margin, height() - 2 * Margin);
    if(!rect.isValid())//窗口部件不够大会导致容纳不下这个矩形直接return
    {
        return;
    }

    PlotSettings settings = zoomStack[curZoom];
    QPen quiteDark = palette().dark().color().light();
    QPen light = palette().light().color();

    for(int i=0; i<=settings.numXTicks; i++)//绘制垂直线以及x轴上的标记符
    {
        int x = rect.left() + (i * (rect.width() - 1)
                               / settings.numXTicks);
        double label = settings.minX + (i * settings.spanX()
                                        / settings.numXTicks);
        painter->setPen(quiteDark);
        painter->drawLine(x, rect.top(), x, rect.bottom());
        painter->setPen(light);
        painter->drawLine(x, rect.bottom(), x, rect.bottom() + 5);
        painter->drawText(x - 50, rect.bottom() + 5, 100, 20,
                          Qt::AlignHCenter | Qt::AlignTop,
                          QString::number(label));
    }
    for(int j = 0; j<=settings.numYTicks; j++)//绘制水平线以及y轴上的标记符
    {
        int y = rect.bottom() - (j*(rect.height() - 1)
                                 / settings.numYTicks);
        double label = settings.minY + (j * settings.spanY()
                                        / settings.numYTicks);
        painter->setPen(quiteDark);
        painter->drawLine(rect.left(), y, rect.right(), y);
        painter->setPen(light);
        painter->drawLine(rect.left() - 5, y, rect.left(), y);
        painter->drawText(rect.left() - Margin, y - 10, Margin - 5, 20,
                          Qt::AlignRight | Qt::AlignVCenter,
                          QString::number(label));
    }
    painter->drawRect(rect.adjusted(0, 0, -1, -1));
}
void Plotter::drawCurves(QPainter *painter)
{
    static const QColor colorForIds[6] = {
        Qt::red, Qt::green, Qt::blue, Qt::cyan, Qt::magenta, Qt::yellow
    };
    PlotSettings settings = zoomStack[curZoom];
    QRect rect(Margin, Margin,
               width() - 2 * Margin, height() - 2 * Margin);
    if(!rect.isValid())
        return;

    painter->setClipRect(rect.adjusted(+1, +1, -1, -1));//剔除绘图1个像素的边框

    QMapIterator<int, QVector<QPointF> > i(curveMap);//使用迭代器遍历容器cupveMap
    while(i.hasNext())
    {
        i.next();

        int id = i.key();//取出曲线ID
        QVector<QPointF> data = i.value();//取出曲线的各个坐标点
        //QPolygonF::QPolygonF ( int size )
        QPolygonF polyline(data.count());//QPolygonF类提供了一个使用浮点精度的点向量QPolygonF是一个QVector<QPointF>
        for(int j=0; j<data.count(); j++)
        {
            double dx = data[j].x() - settings.minX;
            double dy = data[j].y() - settings.minY;
            double x = rect.left() + (dx * (rect.width() - 1)
                                      / settings.spanX());
            double y = rect.bottom() - (dy * (rect.height() - 1)
                                        / settings.spanY());
            polyline[j] = QPointF(x, y);
        }
        painter->setPen(colorForIds[uint(id) % 6]);
        painter->drawPolyline(polyline);
    }
}
