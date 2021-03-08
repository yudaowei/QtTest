#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


    slider = new QSlider(this);

    slider->setMaximum(200);
    slider->setMinimum(0);



    setFixedSize(800, 480);
    label = new QLabel(this);

    label->setGeometry(400,50,100,50);

    connect(this->slider,SIGNAL(valueChanged(int)),this,SLOT(test(int)));



    mylabel = new MYScrollLabel(this);

    mylabel->setGeometry(100, 150,400, 20);

    mylabel->setStyleSheet("{font-size:20px; color: red;}");

    mylabel->clear();

    mylabel->mysetText(QString("本人，年龄：\n  ssssss\n  你好我是余道伟\n"));
}
void MainWindow::test(int a)
{
    label->setText(QString::number(a));
}
MainWindow::~MainWindow()
{
    
}
