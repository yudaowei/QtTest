/********************************************************************************
** Form generated from reading UI file 'propertiesdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTIESDIALOG_H
#define UI_PROPERTIESDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Propertiesdialog
{
public:
    QSpinBox *xspinBox;
    QSpinBox *yspinBox;
    QLineEdit *textLineEdit;
    QLabel *textColorLabel;
    QLabel *outlineColorLabel;
    QLabel *backgroundColorLabel;
    QDialogButtonBox *buttonBox;
    QPushButton *textColorButton;
    QPushButton *outlineColorButton;
    QPushButton *backgroundColorButton;
    QLabel *label;

    void setupUi(QWidget *Propertiesdialog)
    {
        if (Propertiesdialog->objectName().isEmpty())
            Propertiesdialog->setObjectName(QString::fromUtf8("Propertiesdialog"));
        Propertiesdialog->resize(355, 240);
        xspinBox = new QSpinBox(Propertiesdialog);
        xspinBox->setObjectName(QString::fromUtf8("xspinBox"));
        xspinBox->setGeometry(QRect(60, 40, 42, 22));
        yspinBox = new QSpinBox(Propertiesdialog);
        yspinBox->setObjectName(QString::fromUtf8("yspinBox"));
        yspinBox->setGeometry(QRect(110, 40, 42, 22));
        textLineEdit = new QLineEdit(Propertiesdialog);
        textLineEdit->setObjectName(QString::fromUtf8("textLineEdit"));
        textLineEdit->setGeometry(QRect(40, 140, 113, 20));
        textColorLabel = new QLabel(Propertiesdialog);
        textColorLabel->setObjectName(QString::fromUtf8("textColorLabel"));
        textColorLabel->setGeometry(QRect(220, 70, 21, 21));
        outlineColorLabel = new QLabel(Propertiesdialog);
        outlineColorLabel->setObjectName(QString::fromUtf8("outlineColorLabel"));
        outlineColorLabel->setGeometry(QRect(220, 120, 31, 31));
        backgroundColorLabel = new QLabel(Propertiesdialog);
        backgroundColorLabel->setObjectName(QString::fromUtf8("backgroundColorLabel"));
        backgroundColorLabel->setGeometry(QRect(230, 180, 31, 21));
        buttonBox = new QDialogButtonBox(Propertiesdialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 200, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textColorButton = new QPushButton(Propertiesdialog);
        textColorButton->setObjectName(QString::fromUtf8("textColorButton"));
        textColorButton->setGeometry(QRect(260, 70, 75, 23));
        outlineColorButton = new QPushButton(Propertiesdialog);
        outlineColorButton->setObjectName(QString::fromUtf8("outlineColorButton"));
        outlineColorButton->setGeometry(QRect(270, 180, 75, 23));
        backgroundColorButton = new QPushButton(Propertiesdialog);
        backgroundColorButton->setObjectName(QString::fromUtf8("backgroundColorButton"));
        backgroundColorButton->setGeometry(QRect(250, 120, 75, 23));
        label = new QLabel(Propertiesdialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 20, 54, 12));

        retranslateUi(Propertiesdialog);

        QMetaObject::connectSlotsByName(Propertiesdialog);
    } // setupUi

    void retranslateUi(QWidget *Propertiesdialog)
    {
        Propertiesdialog->setWindowTitle(QApplication::translate("Propertiesdialog", "Form", 0, QApplication::UnicodeUTF8));
        textColorLabel->setText(QString());
        outlineColorLabel->setText(QString());
        backgroundColorLabel->setText(QString());
        textColorButton->setText(QApplication::translate("Propertiesdialog", "\345\255\227\344\275\223\350\211\262", 0, QApplication::UnicodeUTF8));
        outlineColorButton->setText(QApplication::translate("Propertiesdialog", "\345\272\225\347\272\277\350\211\262", 0, QApplication::UnicodeUTF8));
        backgroundColorButton->setText(QApplication::translate("Propertiesdialog", "\350\203\214\346\231\257\350\211\262", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Propertiesdialog", "\345\235\220\346\240\207\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Propertiesdialog: public Ui_Propertiesdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTIESDIALOG_H
