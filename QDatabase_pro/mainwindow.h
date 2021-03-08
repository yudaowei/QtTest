#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "employeeform.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QVariant>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QTableView>
#include <QAbstractItemView>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QItemSelectionModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_list_clicked();
    void on_add_clicked();
    void on_clear_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_change_clicked();
    void updateEmployeeView();
    void on_addDept_clicked();
    void on_delDept_clicked();

    void on_editEmpl_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db ;
    QSqlDatabase db2;
    QSqlDatabase db3;
    bool createConnect();
    bool createConnect2();
    bool createConnect3();
    void creatDepartmenPanel();
    void createEmployeePanel();
    void loadingViewData2();
    void loadingViewData3();
};
#endif // MAINWINDOW_H
