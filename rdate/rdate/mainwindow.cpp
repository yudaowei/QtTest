#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString cmd = "date -s " ;
    QString cmd2 = + "\"" + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + "\"";
    cmd+=cmd2;
    system(cmd.toLocal8Bit().constData());
    system("hwclock -w");
}
