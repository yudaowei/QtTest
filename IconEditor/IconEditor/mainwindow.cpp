#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    icon = new IconEditor(this);
    setCentralWidget(icon);
    icon->setPenColor(Qt::red);
    icon->setIconImage(QImage("./image/icon.png"));
    icon->sizeHint();
}

MainWindow::~MainWindow()
{
    delete ui;
}
