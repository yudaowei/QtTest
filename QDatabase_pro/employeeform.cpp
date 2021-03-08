#include "employeeform.h"
#include "ui_employeeform.h"

EmployeeForm::EmployeeForm(int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeForm)
{
    ui->setupUi(this);
    addButton = new QPushButton("Add");
    deleteButton = new QPushButton("delete");
    ui->buttonBox->addButton(addButton, QDialogButtonBox::ActionRole);
    ui->buttonBox->addButton(deleteButton, QDialogButtonBox::ActionRole);
    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit->setDate(QDate::currentDate());
    showDatabase(id);
    connect(addButton, SIGNAL(clicked()), this, SLOT(addEmployee()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteEmployee()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(chooseDepatment(int)));


}

EmployeeForm::~EmployeeForm()
{
    delete ui;
}
void EmployeeForm::showDatabase(int id)//将数据库的一部分记录显示在窗口的小部件上
{
    QSqlDatabase db = QSqlDatabase::database("OTHER2");
    if(!db.isValid()){
        qDebug()<<"db unValide!"<<__FUNCTION__;
        this->close();
    }

    tableModel = new QSqlRelationalTableModel(this, db);
    tableModel->setTable("employee");//选定显示的表格
    tableModel->setRelation(2, QSqlRelation("department", "id", "name"));//设置数据库第二列外键关系
//    tableModel->setSort(1, Qt::AscendingOrder);//对表格第一列进行排序
    tableModel->setFilter(QString("departmentid = %1").arg(id));
    tableModel->select();
    qDebug()<<tableModel->rowCount();

    QSqlTableModel *relationModel = tableModel->relationModel(2);//获取第二列的外键模型
    ui->comboBox->setModel(relationModel);//把comboBox当作relationModel的视图
    ui->comboBox->setModelColumn(relationModel->fieldIndex("name"));//指定模型的列,comboBox只能显示一列数据,默认是第一列

    mapper = new QDataWidgetMapper(this);//实现数据模型的一部分映射到窗体部件中
    mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);//设置修改内容后自动提交
    mapper->setModel(tableModel);//指定要映射的模型
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));//对于含有外键的模型需要指定一个关系委托
    mapper->addMapping(ui->EditName, 1);
    mapper->addMapping(ui->comboBox, 2);
    mapper->addMapping(ui->EditEmail, 3);
    mapper->addMapping(ui->dateEdit, 4);

    if(id != -1 && tableModel->rowCount() != 0){
        mapper->setCurrentIndex(0);
//        for(int row=0 ; row<tableModel->rowCount(); row++){
//            QSqlRecord record = tableModel->record(row);
//            qDebug()<<record.value(0).toInt();
//            if(record.value(0).toInt() == id){
//                mapper->setCurrentIndex(row);
//                break;
//            }
        }
//    }else{
//        mapper->toFirst();
//    }
}

void EmployeeForm::on_First_clicked()
{
    mapper->toFirst();
}
void EmployeeForm::on_previous_clicked()
{
    mapper->toPrevious();
}
void EmployeeForm::on_next_clicked()
{
    mapper->toNext();
}
void EmployeeForm::on_Last_clicked()
{
    mapper->toLast();
}
void EmployeeForm::addEmployee()
{
    int row = mapper->currentIndex();
    mapper->submit();
    tableModel->insertRow(row);
    mapper->setCurrentIndex(row);

    ui->EditName->clear();
    ui->EditEmail->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->EditName->setFocus();
}
void EmployeeForm::deleteEmployee()
{
    int row = mapper->currentIndex();
    tableModel->removeRow(row);
    mapper->submit();
    mapper->setCurrentIndex(qMin(row,tableModel->rowCount() - 1));
}
void EmployeeForm::chooseDepatment(int index)
{
    tableModel->setFilter(QString("departmentid = %1").arg(index+1));
    tableModel->select();
    qDebug()<<tableModel->rowCount()<<"sss";
    mapper->setCurrentIndex(0);
}
