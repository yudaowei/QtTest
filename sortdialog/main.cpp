#include <QApplication>
#include <QUiLoader>
#include <QLineEdit>
#include <QDebug>
#include <QFile>
#include "SortDialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SortDialog w;
    w.setColumnRange('C', 'F');
    w.show();

/*
 *动态对话框,直接加载ui文件,无需将ui文件转化为C++代码
*/
    QUiLoader uiloader;//使用这个类要在pro文件中添加 CONFIG += uitools
    QFile file("gotocelldialog.ui");
    QWidget *sortDialog = uiloader.load(&file);
    sortDialog->show();
    if(sortDialog)
    {
        QLineEdit *lineEdit =
                sortDialog->findChild<QLineEdit *>("lineEdit");//用这种方式可以访问动态对话框的子控件
        if(lineEdit)
        {
            qDebug()<<lineEdit->text()<<"111";
        }
    }

    return a.exec();
}
