#ifndef CITYSCAPE_H
#define CITYSCAPE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "cityview.h"
#include "Annotation.h"
#include "cityblock.h"

class Cityscape : public QMainWindow
{
    Q_OBJECT
    
public:
    Cityscape(QWidget *parent = 0);
    ~Cityscape();
private:
    void generateCityBlocks();

    QGraphicsScene *scene;
    CityView *view;
};

#endif // CITYSCAPE_H
