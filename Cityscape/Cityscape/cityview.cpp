﻿#include "cityview.h"

CityView::CityView(QWidget *parent)
    :QGraphicsView(parent)
{
    setDragMode(ScrollHandDrag);
}
void CityView::wheelEvent(QWheelEvent *event)
{
    double numDegrees = event->delta() / 8.0;
    double numSteps = numDegrees / 15.0;
    double factor = pow(1.125, numSteps);
    scale(factor, factor);
}
