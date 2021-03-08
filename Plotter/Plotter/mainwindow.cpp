#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Plotter *plotter = new Plotter(this);
    plotter->sizeHint();
    setCentralWidget(plotter);
    int id[2] = {0, 1};
    temp[0].resize(30);
    temp[1].resize(30);


    for(double i=0; i<10; i=i+0.001)
    {
        QPointF fill;
        double x = generateRand(0.0, 10.0);
        fill.setX(fill.x() + i);
        fill.setY(fill.y() + formula(i, 1));
        temp[0].append(fill);
    }
    plotter->setCurveData(id[1], temp[0]);
    for(double i=0; i<10; i=i+0.001)
    {

        QPointF fill;
        fill.setX(fill.x() + i);
        fill.setY(fill.y() + formula(i, 2));
        temp[1].append(fill);
    }
    plotter->setCurveData(id[0], temp[1]);

}
double MainWindow::formula(double x, int way)
{
    switch (way)
    {
    case 1:
        return cos(x);
    case 2:
        return sin(x + 1);
    }
}
float MainWindow::generateRand(float min, float max) // 生成区间的随机浮点数
{
    static bool seedStatus;
    if (!seedStatus)
    {
        qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
        seedStatus = true;
    }
    if(min > max)
    {
        float temp = min;
        min = max;
        max = temp;
    }
    double diff = fabs(max - min);
    double m1 = (double)(qrand() % 100) / 100;
    double retval = min + m1 * diff;
    return retval;
}

MainWindow::~MainWindow()
{
    delete ui;
}
