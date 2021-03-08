#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "plotter.h"
#include <QTime>
#include <QVector>
#include <math.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    float generateRand(float min, float max);
    Ui::MainWindow *ui;
    QVector<QPointF> temp[2];
    double formula(double x, int way);
};

#endif // MAINWINDOW_H
