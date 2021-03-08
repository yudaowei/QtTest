#include <QApplication>
#include "mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    int currentScreenWid = QApplication::desktop()->width();
    int currentScreenHei  = QApplication::desktop()->height();
    qDebug()<<currentScreenWid;
    qDebug()<<currentScreenHei;

    w.setGeometry(0,0,currentScreenWid,currentScreenHei);
    w.show();
    
    return a.exec();
}
