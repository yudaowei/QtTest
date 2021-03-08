#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    oventimer = new OvenTimer(this);

    setCentralWidget(oventimer);


}
void MainWindow::paintEvent(QPaintEvent *)
{

}

MainWindow::~MainWindow()
{
    delete ui;
}
