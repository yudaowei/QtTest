#include "ticker.h"

Ticker::Ticker(QWidget *parent) :
    QWidget(parent)
{
    offset = 0;//初始偏移量为0
    myTimerId = 0;//定时器ID通常为非0,以0表示定时器还没启动
}
void Ticker::setText(const QString &newText)
{
    myText = newText;
    update();//强制产生一个绘制事件
    updateGeometry();//通知布局系统此小部件已更改，可能需要更改几何形状。
}
QSize Ticker::sizeHint() const
{
    return fontMetrics().size(0, text());//fontMetrics()返回widget当前字体的字体指标相当于QFontMetrics(widget->font())。
}
void Ticker::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    int textWidth = fontMetrics().width(text());
    if(textWidth < 1)
        return;
    int x = -offset;
    while(x < width())
    {
        painter.drawText(x, 0, textWidth, height(),
                         Qt::AlignLeft | Qt::AlignVCenter, text());
        x += textWidth;
    }
}
void Ticker::showEvent(QShowEvent *)
{
    myTimerId = startTimer(30);
}

void Ticker:: timerEvent(QTimerEvent *event)
{
    if(event->timerId() == myTimerId)
    {
        ++offset;
        if(offset >= fontMetrics().width(text()))
            offset = 0;
        scroll(-1, 0);//往左滚动一个像素
        //本来可以用update()代替scroll(),但使用scroll()会更有效率,它只是简单的移动屏幕上已经存在的像素
    }
    else
    {
        QWidget::timerEvent(event);//定时器不是我们所关注的定时器则把它传给基类
    }
}
void Ticker::hideEvent(QHideEvent *)
{
    killTimer(myTimerId);
    myTimerId = 0;
}
