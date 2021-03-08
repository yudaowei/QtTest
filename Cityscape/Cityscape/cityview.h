#ifndef CITYVIEW_H
#define CITYVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <math.h>

class CityView : public QGraphicsView
{
    Q_OBJECT
public:
    CityView(QWidget *parent = 0);
protected:
    void wheelEvent(QWheelEvent *event);
};

#endif // CITYVIEW_H
