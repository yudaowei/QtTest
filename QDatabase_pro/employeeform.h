#ifndef EMPLOYEEFORM_H
#define EMPLOYEEFORM_H

#include <QDialog>
#include <QPushButton>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>
#include <QDebug>
#include <QDataWidgetMapper>
#include <QSqlRelationalDelegate>
#include <QSqlRecord>
#include <QComboBox>

namespace Ui {
class EmployeeForm;
}

class EmployeeForm : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeForm(int id, QWidget *parent = nullptr);
    ~EmployeeForm();

private slots:
    void on_First_clicked();
    void on_previous_clicked();
    void on_next_clicked();
    void on_Last_clicked();
    void addEmployee();
    void deleteEmployee();
    void chooseDepatment(int index);

private:
    QPushButton *addButton;
    QPushButton *deleteButton;
    QDataWidgetMapper *mapper;
    QSqlRelationalTableModel *tableModel;
    void showDatabase(int id);
    Ui::EmployeeForm *ui;
};

#endif // EMPLOYEEFORM_H
