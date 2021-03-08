#include <QApplication>
#include "mainwindow.h"
#include "currencymodel.h"
#include <QTableView>
#include <QMap>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
