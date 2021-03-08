#include "paintlabel.h"

paintLabel::paintLabel(QWidget *parent) :
    QLabel(parent)
{
}
void paintLabel::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    // 抗锯齿 绘制弧线时启用抗锯齿图形效果更好
    painter.setPen(QPen(Qt::black, 12, Qt::DashDotLine,
                    Qt::RoundCap));
    painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    //画刷填充
    painter.drawEllipse(0, 0, 400, 240);
}
