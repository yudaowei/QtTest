/********************************************************************************
** Form generated from reading UI file 'DiretoryViewer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIRETORYVIEWER_H
#define UI_DIRETORYVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DiretoryViewer
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DiretoryViewer)
    {
        if (DiretoryViewer->objectName().isEmpty())
            DiretoryViewer->setObjectName(QString::fromUtf8("DiretoryViewer"));
        DiretoryViewer->resize(797, 517);
        buttonBox = new QDialogButtonBox(DiretoryViewer);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(460, 470, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DiretoryViewer);
        QObject::connect(buttonBox, SIGNAL(accepted()), DiretoryViewer, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DiretoryViewer, SLOT(reject()));

        QMetaObject::connectSlotsByName(DiretoryViewer);
    } // setupUi

    void retranslateUi(QDialog *DiretoryViewer)
    {
        DiretoryViewer->setWindowTitle(QApplication::translate("DiretoryViewer", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DiretoryViewer: public Ui_DiretoryViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIRETORYVIEWER_H
