#ifndef OVENTIMER_H
#define OVENTIMER_H

#include <QWidget>
#include <QDateTime>
#include <QTimer>
#include <QMouseEvent>
#include <QPointF>
#include <math.h>
#include <QPainter>

class OvenTimer : public QWidget
{
    Q_OBJECT
public:
    explicit OvenTimer(QWidget *parent = 0);

    void setDuration(int secs);
    int duration() const;
    void draw(QPainter *painter);
    
signals:
    void timeout();
    
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    QDateTime finishTime;
    QTimer *updateTimer;
    QTimer *finishTimer;
    
    const double DegreesPerMinute = 7.0;//一分钟转7个角度
    const double DegreesPerSecond = DegreesPerMinute / 60;
    const int MaxMinutes = 45;
    const int MaxSeconds = MaxMinutes * 60;
    const int UpdateInterval = 5;//间隔
};

#endif // OVENTIMER_H
