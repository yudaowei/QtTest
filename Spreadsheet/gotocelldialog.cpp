#include "gotocelldialog.h"

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));

    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
    //accept()/reject()都能关闭对话框,accept将对话框返回结果变量设置为QDialog::Accepted=1
    //reject设置为QDialog::Rejected=0
}

/*
 *setupUi函数会自动将符合 on_objectName_signalName()
 *命名惯例的任意槽与相应的objectName的signalName()
 *信号连接到一起
 */
void GoToCellDialog::on_lineEdit_textChanged()
{
    okButton->setEnabled(lineEdit->hasAcceptableInput());
}
