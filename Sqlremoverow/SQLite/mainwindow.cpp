#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createconnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::createconnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/wangyunb/Work_Documents/NorthProject/UI_Source/yu/working/demo/Sqlremoverow/SQLite/test.db");
    if(!db.open()){
        qDebug()<<"open failed";
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    QSqlTableModel model;
    model.setTable("test");
    model.select();
    for(int i=0; i<model.rowCount(); i++){
        QSqlRecord record = model.record(i);
        ui->textEdit->append(record.value("name").toString().trimmed() + "\t" + record.value("age").toString() + "\t" + record.value("ssss").toString());
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QSqlTableModel model;
    model.setTable("test");
    model.insertRow(model.rowCount());
    model.setData(model.index(model.rowCount()-1, 0), ui->lineEdit->text());
    model.setData(model.index(model.rowCount()-1, 1), ui->lineEdit_2->text());
    model.setData(model.index(model.rowCount()-1, 2), ui->lineEdit_3->text());
    model.submitAll();
}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlTableModel model;
    model.setTable("test");
    model.setFilter(QString("name = '%1'").arg(ui->lineEdit->text()));
    model.select();
    if(model.rowCount() > 0){
        model.removeRows(0 , 1);
        model.submitAll();
    }
}
