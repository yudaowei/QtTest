#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createConnect();
    createConnect2();
    createConnect3();
    loadingViewData2();
    loadingViewData3();
//    EmployeeForm *test = new EmployeeForm(1, this);
//    test->show();
}

MainWindow::~MainWindow()
{
    db.close();
    db2.close();
    db3.close();
    delete ui;
}

bool MainWindow::createConnect()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/Qt_Project/Database/QDatabase_pro/database/data.db");
    if(!db.open()){
        QApplication::beep();
        QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                              db.lastError().text());
        return false;
    }
    return true;
}
bool MainWindow::createConnect2()
{
    db2 = QSqlDatabase::addDatabase("QSQLITE", "OTHER");
    db2.setDatabaseName("E:/Qt_Project/Database/QDatabase_pro/database/data2.db");
    if(!db2.open()){
        QApplication::beep();
        QMessageBox::critical(nullptr, QObject::tr("Database2 Error"),
                              db2.lastError().text());
        return false;
    }
    return true;

}
bool MainWindow::createConnect3()
{
    db3 = QSqlDatabase::addDatabase("QSQLITE", "OTHER2");
    db3.setDatabaseName("E:/Qt_Project/Database/QDatabase_pro/database/data3.db");
    if(!db3.open()){
        QApplication::beep();
        QMessageBox::critical(nullptr, QObject::tr("Database3 Error"),
                              db2.lastError().text());
        return false;
    }
    return true;
}
void MainWindow::on_pushButton_clicked()
{
    createConnect();
}

void MainWindow::on_list_clicked()
{
    ui->textEdit->clear();
    QSqlQuery query;
    query.exec("select * from stu_info");
    if(!query.isActive()){
        QMessageBox::warning(this, QObject::tr("Database Error"), query.lastError().text());
    }
    while(query.next()){
        ui->textEdit->append(query.value(0).toString()+"\t"+query.value(1).toString()+"\t"+query.value(2).toString());
    }
}

void MainWindow::on_add_clicked()
{
    QSqlQuery query;
    query.prepare("insert into stu_info( name, age, address ) values( :name, :age, :address )");
    query.bindValue(":name", ui->lineEdit->text());
    query.bindValue(":age", ui->lineEdit_2->text());
    query.bindValue(":address", ui->lineEdit_3->text());
    query.exec();
    if(!query.isActive()){
        QMessageBox::warning(this, QObject::tr("Database Error"), query.lastError().text());
    }
}

void MainWindow::on_clear_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
    QSqlTableModel *model = new QSqlTableModel(this, db2);
    model->setTable("chengji");
//    model->setFilter("yuwen>70");
    model->select();//结果集放在QSqlRecord
    for(int i=0 ; i<model->rowCount(); i++){
        QSqlRecord record = model->record(i);
//        for(int j=0; j<model->columnCount(); j++){
//             ui->textEdit->append(record.value(j).toString());
//        }
        ui->textEdit->append(record.value(record.indexOf("name")).toString() + "\t" +
                             record.value(record.indexOf("yuwen")).toString() + "\t" +
                             record.value(record.indexOf("shuxue")).toString() + "\t" +
                             record.value(record.indexOf("yingyu")).toString() );
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlTableModel *model = new QSqlTableModel(this, db2);
    model->setTable("chengji");
    int row = model->rowCount();
    model->insertRows(row, 1);
    model->setData(model->index(model->rowCount()-1, 0), ui->lineEdit_4->text());
    model->setData(model->index(model->rowCount()-1, 1), ui->lineEdit_6->text());
    model->setData(model->index(model->rowCount()-1, 2), ui->lineEdit_5->text());
    model->setData(model->index(model->rowCount()-1, 3), ui->lineEdit_7->text());
    bool ok = model->submitAll();
    if(!ok){
        QMessageBox::warning(this, QObject::tr("Database Error"), model->lastError().text());
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QSqlTableModel *model = new QSqlTableModel(this, db2);
    model->setTable("chengji");
    model->setFilter(QString("name = '%1'").arg(ui->lineEdit_4->text()));
    model->select();
    if(model->rowCount() > 0){
        qDebug()<<model->rowCount();
        model->removeRow(0);
        model->submitAll();
    }
}

void MainWindow::on_change_clicked()
{
    QSqlTableModel *model = new QSqlTableModel(this, db2);
    model->setTable("chengji");
    model->setFilter(QString("name = '%1'").arg(ui->lineEdit_4->text()));
    model->select();
    if(model->rowCount() == 1){
        QSqlRecord record = model->record(0);
        record.setValue(1, ui->lineEdit_6->text());
        record.setValue("shuxue", ui->lineEdit_5->text());
        record.setValue(3,ui->lineEdit_7->text());
        model->setRecord(0, record);
        model->submitAll();
    }
}
void MainWindow::loadingViewData2()
{
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("stu_info");
    model->setHeaderData(0,Qt::Horizontal,"name");
    model->setHeaderData(1,Qt::Horizontal,"age");
    model->setHeaderData(2,Qt::Horizontal,"address");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->resizeColumnsToContents();
//    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}
void MainWindow::loadingViewData3()//有外键的数据库显示再view中
{
    QSqlRelationalTableModel *departmentModel = new QSqlRelationalTableModel(this, db3);
    departmentModel->setTable("department");
    departmentModel->setRelation(2, QSqlRelation("location", "id", "name"));
    departmentModel->setHeaderData(1, Qt::Horizontal, "Dept.");
    departmentModel->setHeaderData(2, Qt::Horizontal, "Location");
    departmentModel->select();

    ui->DepartementsView->setModel(departmentModel);
    ui->DepartementsView->setItemDelegate(new QSqlRelationalDelegate(this));
    ui->DepartementsView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->DepartementsView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->DepartementsView->setColumnHidden(0, true);
    ui->DepartementsView->resizeColumnsToContents();
    ui->DepartementsView->horizontalHeader()->setStretchLastSection(true);

    connect(ui->DepartementsView->selectionModel(), SIGNAL(currentRowChanged(const QModelIndex &,const QModelIndex &)), this, SLOT(updateEmployeeView()));

    QSqlRelationalTableModel *employeeModel = new QSqlRelationalTableModel(this, db3);
    employeeModel->setTable("employee");
    employeeModel->setRelation(2, QSqlRelation("department", "id", "name"));
    employeeModel->setHeaderData(1, Qt::Horizontal,"Name");
    employeeModel->setHeaderData(2, Qt::Horizontal,"Email");
    employeeModel->setHeaderData(3, Qt::Horizontal, "date");

    ui->EmployeesView->setModel(employeeModel);
    ui->EmployeesView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->EmployeesView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->EmployeesView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->EmployeesView->horizontalHeader()->setStretchLastSection(true);
    ui->EmployeesView->setColumnHidden(0, true);
    ui->EmployeesView->setColumnHidden(2, true);
//    ui->EmployeesView->setColumnHidden(4, true);
}
void MainWindow::updateEmployeeView()
{
    QModelIndex index = ui->DepartementsView->currentIndex();
    QSqlRelationalTableModel *departementsModel = static_cast<QSqlRelationalTableModel *>(ui->DepartementsView->model());
    QSqlRelationalTableModel *employeeModel = static_cast<QSqlRelationalTableModel *>(ui->EmployeesView->model());
    if(index.isValid()){
        QSqlRecord record = departementsModel->record(index.row());
        int id = record.value("id").toInt();
        employeeModel->setFilter(QString("departmentid = %1").arg(id));
    }else{
        employeeModel->setFilter("departmentid = -1");
    }
    employeeModel->select();
    ui->EmployeesView->horizontalHeader()->setVisible(employeeModel->rowCount() > 0);
}

void MainWindow::on_addDept_clicked()
{
    QSqlRelationalTableModel *departementsModel = static_cast<QSqlRelationalTableModel *>(ui->DepartementsView->model());
    int row = departementsModel->rowCount();
    departementsModel->insertRow(row);
    QModelIndex index = departementsModel->index(row, 1);
    ui->DepartementsView->setCurrentIndex(index);
    ui->DepartementsView->edit(index);
}

void MainWindow::on_delDept_clicked()
{
    QSqlRelationalTableModel *departementsModel = static_cast<QSqlRelationalTableModel *>(ui->DepartementsView->model());
    QSqlRelationalTableModel *employeeModel = static_cast<QSqlRelationalTableModel *>(ui->EmployeesView->model());
    if(departementsModel == nullptr || employeeModel == nullptr){
        qDebug()<<"changed failed!  "<<__FUNCTION__<<__LINE__;
        return;
    }
    QModelIndex index = ui->DepartementsView->currentIndex();
    if(!index.isValid()){
        return;
    }

    db3.transaction();
    QSqlRecord record = departementsModel->record(index.row());
    int id = record.value(0).toInt();
    qDebug()<<id<<__FUNCTION__;
    employeeModel->setFilter(QString("departmentid = %1").arg(id));
    employeeModel->select();
    qDebug()<<employeeModel->rowCount() ;
    if(employeeModel->rowCount() > 0){
        int r = QMessageBox::warning(this, "Delete Dpartment",
                                     QString("Delete %1 and all its employees?").arg(departementsModel->record(0).value(1).toString()),
                                     QMessageBox::Yes | QMessageBox::No);
        if(r == QMessageBox::No){
            db3.rollback();
            return;
        }
        for(int i=0 ; i<employeeModel->rowCount(); i++)
            employeeModel->removeRow(i);
        employeeModel->submit();
    }
    departementsModel->removeRow(index.row());
    departementsModel->submitAll();
    db3.commit();

    updateEmployeeView();
    ui->DepartementsView->setFocus();
}

void MainWindow::on_editEmpl_clicked()
{
    int employeeID = -1;
    QSqlRelationalTableModel *departementsModel = static_cast<QSqlRelationalTableModel *>(ui->DepartementsView->model());
    QModelIndex index = ui->DepartementsView->currentIndex();
    if(index.isValid()){
        //索引有效 提取当前选中的员工ID  用于创建修改员工信息的对话框
        employeeID = departementsModel->record(index.row()).value("id").toInt();
        qDebug()<<employeeID;
        EmployeeForm Form(employeeID, this);
        Form.exec();
    }
    //创建编辑员工信息的对话框
    updateEmployeeView();
}
