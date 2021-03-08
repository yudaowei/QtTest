#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontDatabase>
#include "Scrolllabel.h"
#include <QSlider>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
private slots:
    void test(int a);

public:
    QSlider* slider;
    MainWindow(QWidget *parent = 0);
    MYScrollLabel *mylabel;
    QLabel *label;
    ~MainWindow();
};

#endif // MAINWINDOW_H
