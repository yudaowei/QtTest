#include <QtGui>
#include "iconeditor.h"

IconEditor::IconEditor(QWidget *parent)
	:QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	
	curColor = Qt::black;
    zoom = 6;
    image = QImage(16, 16, QImage::Format_ARGB32);//初始化为16*16像素大小和32位的ARGB颜色格式,这种颜色格式支持透明效果
    image.fill(qRgba(0,0,0,0));//填充白色且透明
	
}
QSize IconEditor::sizeHint() const//重载sizeHint
{
    QSize size = zoom * image.size();
    if(zoom >= 3)
    {
        size += QSize(1, 1);
    }
    return size;
}
void IconEditor::setPenColor(const QColor &newColor)//设置画笔颜色
{
    curColor = newColor;
}
void IconEditor::setIconImage(const QImage &newImage)//设置需要编辑的图像
{
    if(newImage != image)
    {
        image = newImage.convertToFormat(QImage::Format_ARGB32);//转换图像格式 带alpha缓冲的32位图像
        update();
        updateGeometry();
    }
}
void IconEditor::setZoomFactor(int newZoom)
{
    if(newZoom < 1)
        newZoom = 1;
    if(newZoom != zoom)
    {
        zoom = newZoom;
        update();//调用update启动一次paintEvent
        updateGeometry();
    }
}
/*
 *  绘制事件:1,在窗口部件第一次显示时系统会自动产生一个绘制事件,从而强制绘制这个窗口部件本身
 *          2,当重新调整窗口部件大小的时候,系统也会产生一个绘制事件
 *          3,当窗口部件被其他窗口部件遮挡,然后又再次显示出来的时候,
 *            就会对那些隐藏的区域产生一个绘制事件(除非这个窗口系统存储了整个区域)
*/
void IconEditor::paintEvent(QPaintEvent *event)//核心函数
{
    QPainter painter(this);
    if(zoom >= 3)
    {
        painter.setPen(palette().foreground().color());//palette()调色板
        for(int i = 0; i <= image.width(); i++)
        {
            painter.drawLine(zoom * i, 0, zoom * i, zoom * image.height());//画直线
        }

        for(int j = 0; j <= image.height(); j++)
        {
            painter.drawLine(0, zoom * j, zoom * image.width(), zoom * j);
        }
    }
    for(int i=0; i<image.width(); i++)
    {
        for(int j=0; j<image.height(); j++)
        {
            QRect rect = pixelRect(i, j);//返回一个矩形
            if(!event->region().intersect(rect).isEmpty())//region返回更新区域,intersect插入一个矩形
            {
                QColor color = QColor::fromRgba(image.pixel(i, j));
                if(color.alpha() < 255)
                    painter.fillRect(rect, Qt::white);
                painter.fillRect(rect, color);
            }
        }
    }
}
QRect IconEditor::pixelRect(int i, int j) const
{
    if(zoom >= 3)
    {
        return QRect(zoom * i + 1, zoom * j + 1, zoom - 1, zoom-1);
    }
    else
    {
        return QRect(zoom * i, zoom * j, zoom, zoom);
    }
}
void IconEditor::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        setImagePixel(event->pos(), true);
    }
    else if(event->button() == Qt::RightButton)
    {
        setImagePixel(event->pos(), false);
    }
}
void IconEditor::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
        setImagePixel(event->pos(), true);
    else if(event->buttons() & Qt::RightButton)
        setImagePixel(event->pos(), false);
}
void IconEditor::setImagePixel(const QPoint &pos, bool opaque)
{
    int i = pos.x() / zoom;
    int j = pos.y() / zoom;
    if(image.rect().contains(i, j))
    {
        if(opaque)
        {
            image.setPixel(i, j, penColor().rgba());
        }
        else
        {
            image.setPixel(i, j, qRgba(0,0,0,0));
        }
        update(pixelRect(i, j));
    }
}
