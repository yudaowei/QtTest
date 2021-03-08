#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "currencymodel.h"
#include "citymodel.h"
#include "trackdelegate.h"
#include <QTableView>
#include <QTableWidget>
#include <QHeaderView>
#include <QDialog>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    CurrencyModel *currencyModel;
    QMainWindow* CityWidget;
    QDialog * Delegate;
    CityModel* cityModel;
};

#endif // MAINWINDOW_H
