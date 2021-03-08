#include "oventimer.h"

OvenTimer::OvenTimer(QWidget *parent) :
    QWidget(parent)
{
    finishTime = QDateTime::currentDateTime();
    updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(update()));//每间隔5秒刷新部件外观

    finishTimer = new QTimer(this);
    finishTimer->setSingleShot(true);//此属性被设置为true时,定时器触发一次就自动停止
    connect(finishTimer, SIGNAL(timeout()), this, SIGNAL(timeout()));//信号与信号连接
    connect(finishTimer, SIGNAL(timeout()), updateTimer, SLOT(stop()));

    QFont font;
    font.setPointSize(8);//字体磅值设置为8
    setFont(font);
}
void OvenTimer::setDuration(int secs)
{
    secs = qBound(0, secs, MaxSeconds);
    /*qBound表达式相当于
    if(secs < 0){
        secs = 0;
    }else if(secs > MaxSeconds){
        secs = MaxSeconds;
    }
    */

    finishTime = QDateTime::currentDateTime().addSecs(secs);//当前时间加上时间间隔得到结束时间

    if(secs > 0){
        updateTimer->start(UpdateInterval * 1000);
        finishTimer->start(secs * 1000);
    }else{
        updateTimer->stop();
        finishTimer->stop();
    }
    update();
}
int OvenTimer::duration() const//返回定时器完成前剩余的秒数
{
    int secs = QDateTime::currentDateTime().secsTo(finishTime);
    if(secs < 0)
        secs = 0;
    return secs;
}
void OvenTimer::draw(QPainter *painter)
{
    static const int triangle[3][2] = {
        { -2, -49 },
        { +2, -49 },
        { 0, -47 }
    };

    QPen thickPen(palette().foreground(), 1.5);
    QPen thinPen(palette().foreground(), 0.5);
    QColor niceBlue(150, 150, 200);

    painter->setPen(thinPen);
    painter->setBrush(palette().foreground());
    painter->drawPolygon(QPolygon(3, &triangle[0][0]));//在窗口部件顶部绘制一个小三角形

    QConicalGradient conGradient(0, 0, -90.0);//锥形渐变
    conGradient.setColorAt(0.0, Qt::darkGray);
    conGradient.setColorAt(0.2, niceBlue);
    conGradient.setColorAt(0.5, Qt::white);
    conGradient.setColorAt(1.0, Qt::darkGray);

    painter->setBrush(conGradient);
    painter->drawEllipse(-46, -46, 92, 92);//填充椭圆

    QRadialGradient haloGradient(0,0,20,0,0);//辐射渐变
    haloGradient.setColorAt(0.0, Qt::lightGray);
    haloGradient.setColorAt(0.8, Qt::darkGray);
    haloGradient.setColorAt(0.9, Qt::white);
    haloGradient.setColorAt(1.0, Qt::black);

    painter->setPen(Qt::NoPen);
    painter->setBrush(haloGradient);
    painter->drawEllipse(-20, -20, 40, 40);//填充椭圆

    QLinearGradient knobGradient(-7, -25, 7, -25);//线性渐变
    knobGradient.setColorAt(0.0, Qt::black);
    knobGradient.setColorAt(0.2, niceBlue);
    knobGradient.setColorAt(0.3, Qt::lightGray);
    knobGradient.setColorAt(0.8, Qt::white);
    knobGradient.setColorAt(1.0, Qt::black);

    painter->rotate(duration() * DegreesPerSecond);//坐标旋转 旋转角度由用户设定时间长短决定
    painter->setBrush(knobGradient);//填充模式
    painter->setPen(thinPen);//设置绘制轮廓的QPen

    painter->drawRoundedRect(-7, -25, 14, 50, 99, 49);//填充无角矩形

    for(int i = 0; i <= MaxMinutes; i++){//绘制刻度以及数字
        painter->save();
        painter->rotate(-i * DegreesPerMinute);//通过将坐标系旋转绘制出所有刻度
        if(i % 5 == 0){//大刻度
            painter->setPen(thickPen);
            painter->drawLine(0, -41, 0, -44);
            painter->drawText(-15, -41, 30, 30,
                              Qt::AlignHCenter | Qt::AlignTop,
                              QString::number(i));
        }else{//小刻度
            painter->setPen(thinPen);
            painter->drawLine(0, -42, 0, -44);
        }
        painter->restore();
    }
}
void OvenTimer::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);//设置抗锯齿

    int side = qMin(width(), height());//返回小值
    //如果没有设置视口为正方形,当窗口部件被缩放为非正方形时,烤箱定时器就会变为椭圆
    //为了避免这种情况,必须把视口和窗口设置成具有相同纵横比的矩形
    painter.setViewport((width() - side) / 2, (height() - side) / 2,
                        side, side);//将视口裁剪成正方形
    painter.setWindow(-50, -50, 100, 100);//将绘制器窗口设置为给定的矩形，并启用视图转换。

    draw(&painter);
}
    /*用户单击部件时,用数学公式找到最近的刻度,
     *并用这个结果来设置新的持续时间,然后安排
     *一个重绘,用户点的刻度移动到顶部,随着时间
     *逆时针移动到0的位置
    */
void OvenTimer::mousePressEvent(QMouseEvent *event)
{
    QPointF point = event->pos() - rect().center();
    double theta = atan2(-point.x(), -point.y()) * 180.0 / M_PI;
    setDuration(duration() + int(theta / DegreesPerSecond));
    update();
}
