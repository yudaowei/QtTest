#include <QApplication>
#include "mainwindow.h"
#include "mythread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MyThread r[2];
    r[0].start();
    r[1].start();
    return a.exec();
}
