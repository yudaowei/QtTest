#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->hide();

    qDebug()<<ui->pushButton->text();

    array[0] = ui->pushButton->text().mid(0,1);
    qDebug()<<array[0];
    array[1] = ui->pushButton->text().mid(2,1);
    qDebug()<<array[1];
    array[2] = ui->pushButton->text().mid(3,1);
    qDebug()<<array[2];
    array[3] = ui->pushButton->text().mid(4,1);
    qDebug()<<array[3];

    qDebug()<<ui->pushButton->x();
    qDebug()<<ui->pushButton->y();
//    this->setMouseTracking(true);
    ENkey_board_released();
    catchmouse = new QTimer(this);
    connect(catchmouse, SIGNAL(timeout()), this, SLOT(catchpos()));

    catchmouse_ = new QTimer(this);
    connect(catchmouse_, SIGNAL(timeout()), this, SLOT(catchpos_()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//(coursePoint.y()-ui->pushButton->y()-pos().y())
//(coursePoint.x()-pos()-pos().x()-ui->pushButton->x())

void MainWindow::on_pushButton_pressed()
{
    //按下
    ui->label->show();
    catchmouse->start(10);
}
void MainWindow::catchpos()
{
    coursePoint = ui->pushButton->mapFromGlobal(QCursor::pos());
    qDebug()<<coursePoint.x()/*-pos().x()-ui->pushButton->x()*/;
    qDebug()<<coursePoint.y()/*-pos().y()-ui->pushButton->y()*/;
    switch(coursePoint.x()/30)
    {
        case 0:
        ui->label->setText(array[0]);
            break;
        case 1:
        ui->label->setText(array[1]);
            break;
        case 2:
        ui->label->setText(array[2]);
            break;
        case 3:
        ui->label->setText(array[3]);
            break;
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *)
{
//    coursePoint = QCursor::pos();
//    qDebug()<<QCursor::pos().x();
//    qDebug()<<QCursor::pos().y();
}
void MainWindow::on_pushButton_released()
{
    //释放
    ui->label->hide();
    ui->lineEdit->insert(ui->label->text());
    catchmouse->stop();
}
void MainWindow::ENkey_board_released()
{
    connect(ui->OneEN, SIGNAL(pressed()), this, SLOT(pressed_slot()));
    connect(ui->TowEN, SIGNAL(pressed()), this, SLOT(pressed_slot()));
    connect(ui->ThreeEN, SIGNAL(pressed()), this, SLOT(pressed_slot()));
    connect(ui->FourEN, SIGNAL(pressed()), this, SLOT(pressed_slot()));
    connect(ui->FiveEN, SIGNAL(pressed()), this, SLOT(pressed_slot()));
    connect(ui->SixEN, SIGNAL(pressed()), this, SLOT(pressed_slot()));
    connect(ui->SevenEN, SIGNAL(pressed()), this, SLOT(pressed_slot()));
    connect(ui->EightEN, SIGNAL(pressed()), this, SLOT(pressed_slot()));
    connect(ui->NineEN, SIGNAL(pressed()), this, SLOT(pressed_slot()));
    connect(ui->ZeroEN, SIGNAL(pressed()), this, SLOT(pressed_slot()));

    connect(ui->OneEN, SIGNAL(released()), this, SLOT(released_slot()));
    connect(ui->TowEN, SIGNAL(released()), this, SLOT(released_slot()));
    connect(ui->ThreeEN, SIGNAL(released()), this, SLOT(released_slot()));
    connect(ui->FourEN, SIGNAL(released()), this, SLOT(released_slot()));
    connect(ui->FiveEN, SIGNAL(released()), this, SLOT(released_slot()));
    connect(ui->SixEN, SIGNAL(released()), this, SLOT(released_slot()));
    connect(ui->SevenEN, SIGNAL(released()), this, SLOT(released_slot()));
    connect(ui->EightEN, SIGNAL(released()), this, SLOT(released_slot()));
    connect(ui->NineEN, SIGNAL(released()), this, SLOT(released_slot()));
    connect(ui->ZeroEN, SIGNAL(released()), this, SLOT(released_slot()));
}

void MainWindow::released_slot()
{
    catchmouse_->stop();
    ui->lineEdit->insert(ui->ShowEN->text());
    ui->ShowEN->clear();
}
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
//    catchmouse_->stop();
//    ui->lineEdit->insert(ui->ShowEN->text());
//    ui->ShowEN->clear();
}
void MainWindow::pressed_slot()
{
    btn =  static_cast<QPushButton*>(sender());
//    ui->ShowEN->setText(btn->text().remove("\n"));
    released_text = btn->text().remove("\n");
    catchmouse_->start(10);
}
void MainWindow::catchpos_()
{
    coursePoint = btn->mapFromGlobal(QCursor::pos());
//    qDebug()<<released_text.length();
//    qDebug()<<ui->frameEnKeyBord->width();//200
    qDebug()<<coursePoint.x();
    qDebug()<<coursePoint.y();
    if(released_text.length() == 3)
    {
        switch(coursePoint.x()/20)
        {
            case 0:
                ui->ShowEN->setText(released_text.at(0));
                break;
            case 1:
                ui->ShowEN->setText(released_text.at(1));
                break;
            case 2:
                ui->ShowEN->setText(released_text.at(2));
                break;
        }
    }
    else if(released_text.length() == 4)
    {
        switch(coursePoint.x()/15)
        {
            case 0:
                ui->ShowEN->setText(released_text.at(0));
                break;
            case 1:
                ui->ShowEN->setText(released_text.at(1));
                break;
            case 2:
                ui->ShowEN->setText(released_text.at(2));
                break;
            case 3:
                ui->ShowEN->setText(released_text.at(3));
                break;
        }
    }
}
