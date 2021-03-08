/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QFrame *frameEnKeyBord;
    QPushButton *EightEN;
    QPushButton *TowEN;
    QPushButton *Char1;
    QPushButton *RemoveAll;
    QPushButton *Remove;
    QPushButton *FiveEN;
    QPushButton *SevenEN;
    QPushButton *ZeroEN;
    QPushButton *ThreeEN;
    QPushButton *OneEN;
    QPushButton *Char2;
    QPushButton *Char3;
    QPushButton *FourEN;
    QPushButton *NineEN;
    QPushButton *SixEN;
    QLabel *ShowEN;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(665, 427);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 10, 271, 31));
        lineEdit->setCursor(QCursor(Qt::IBeamCursor));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 300, 121, 61));
        pushButton->setFocusPolicy(Qt::NoFocus);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 250, 101, 31));
        label->setStyleSheet(QString::fromUtf8("background-color:yellow"));
        label->setAlignment(Qt::AlignCenter);
        frameEnKeyBord = new QFrame(centralWidget);
        frameEnKeyBord->setObjectName(QString::fromUtf8("frameEnKeyBord"));
        frameEnKeyBord->setGeometry(QRect(210, 50, 200, 321));
        frameEnKeyBord->setStyleSheet(QString::fromUtf8("QFrame{background-color: rgb(216, 240, 250); border-radius: 10px;}"));
        frameEnKeyBord->setFrameShape(QFrame::StyledPanel);
        frameEnKeyBord->setFrameShadow(QFrame::Raised);
        EightEN = new QPushButton(frameEnKeyBord);
        EightEN->setObjectName(QString::fromUtf8("EightEN"));
        EightEN->setGeometry(QRect(70, 155, 60, 50));
        EightEN->setFocusPolicy(Qt::NoFocus);
        EightEN->setStyleSheet(QString::fromUtf8("QPushButton{outline: none; border-radius: 5px; font-weight: bold; font-size: 18px; color: rgb(25, 25, 112); background-color:rgb(171, 223, 245); } QPushButton:pressed{background-color: rgb(25, 25, 112) ; color: white;}"));
        TowEN = new QPushButton(frameEnKeyBord);
        TowEN->setObjectName(QString::fromUtf8("TowEN"));
        TowEN->setGeometry(QRect(70, 45, 60, 50));
        TowEN->setFocusPolicy(Qt::NoFocus);
        TowEN->setStyleSheet(QString::fromUtf8("QPushButton{outline: none; border-radius: 5px; font-weight: bold; font-size: 18px; color: rgb(25, 25, 112); background-color:rgb(171, 223, 245); } QPushButton:pressed{background-color: rgb(25, 25, 112) ; color: white;}"));
        Char1 = new QPushButton(frameEnKeyBord);
        Char1->setObjectName(QString::fromUtf8("Char1"));
        Char1->setGeometry(QRect(5, 210, 60, 50));
        Char1->setFocusPolicy(Qt::NoFocus);
        Char1->setStyleSheet(QString::fromUtf8("QPushButton{outline: none; border-radius: 5px; font-weight: bold; font-size: 23px; color: rgb(25, 25, 112); background-color:rgb(171, 223, 245); } QPushButton:pressed{background-color: rgb(25, 25, 112) ; color: white;}"));
        RemoveAll = new QPushButton(frameEnKeyBord);
        RemoveAll->setObjectName(QString::fromUtf8("RemoveAll"));
        RemoveAll->setGeometry(QRect(135, 265, 60, 50));
        RemoveAll->setFocusPolicy(Qt::NoFocus);
        RemoveAll->setStyleSheet(QString::fromUtf8("QPushButton{outline: none; border-radius: 5px; font-weight: bold; font-size: 23px; color: rgb(25, 25, 112); background-color:rgb(171, 223, 245); } QPushButton:pressed{background-color: rgb(25, 25, 112) ; color: white;}"));
        Remove = new QPushButton(frameEnKeyBord);
        Remove->setObjectName(QString::fromUtf8("Remove"));
        Remove->setGeometry(QRect(5, 265, 60, 50));
        Remove->setFocusPolicy(Qt::NoFocus);
        Remove->setStyleSheet(QString::fromUtf8("QPushButton{outline: none; border-radius: 5px; font-weight: bold; font-size: 23px; color: rgb(25, 25, 112); background-color:rgb(171, 223, 245); } QPushButton:pressed{background-color: rgb(25, 25, 112) ; color: white;}"));
        FiveEN = new QPushButton(frameEnKeyBord);
        FiveEN->setObjectName(QString::fromUtf8("FiveEN"));
        FiveEN->setGeometry(QRect(70, 100, 60, 50));
        FiveEN->setFocusPolicy(Qt::NoFocus);
        FiveEN->setStyleSheet(QString::fromUtf8("QPushButton{outline: none; border-radius: 5px; font-weight: bold; font-size: 18px; color: rgb(25, 25, 112); background-color:rgb(171, 223, 245); } QPushButton:pressed{background-color: rgb(25, 25, 112) ; color: white;}"));
        SevenEN = new QPushButton(frameEnKeyBord);
        SevenEN->setObjectName(QString::fromUtf8("SevenEN"));
        SevenEN->setGeometry(QRect(5, 155, 60, 50));
        SevenEN->setFocusPolicy(Qt::NoFocus);
        SevenEN->setStyleSheet(QString::fromUtf8("QPushButton{outline: none; border-radius: 5px; font-weight: bold; font-size: 18px; color: rgb(25, 25, 112); background-color:rgb(171, 223, 245); } QPushButton:pressed{background-color: rgb(25, 25, 112) ; color: white;}"));
        ZeroEN = new QPushButton(frameEnKeyBord);
        ZeroEN->setObjectName(QString::fromUtf8("ZeroEN"));
        ZeroEN->setGeometry(QRect(70, 210, 60, 50));
        ZeroEN->setFocusPolicy(Qt::NoFocus);
        ZeroEN->setStyleSheet(QString::fromUtf8("QPushButton{outline: none; border-radius: 5px; font-weight: bold; font-size: 18px; color: rgb(25, 25, 112); background-color:rgb(171, 223, 245); } QPushButton:pressed{background-color: rgb(25, 25, 112) ; color: white;}"));
        ThreeEN = new QPushButton(frameEnKeyBord);
        ThreeEN->setObjectName(QString::fromUtf8("ThreeEN"));
        ThreeEN->setGeometry(QRect(135, 45, 60, 50));
        ThreeEN->setFocusPolicy(Qt::NoFocus);
        ThreeEN->setStyleSheet(QString::fromUtf8("QPushButton{outline: none; border-radius: 5px; font-weight: bold; font-size: 18px; color: rgb(25, 25, 112); background-color:rgb(171, 223, 245); } QPushButton:pressed{background-color: rgb(25, 25, 112) ; color: white;}"));
        ThreeEN->setCheckable(false);
        ThreeEN->setChecked(false);
        ThreeEN->setAutoRepeat(false);
        ThreeEN->setAutoExclusive(false);
        ThreeEN->setAutoDefault(false);
        ThreeEN->setDefault(false);
        ThreeEN->setFlat(false);
        OneEN = new QPushButton(frameEnKeyBord);
        OneEN->setObjectName(QString::fromUtf8("OneEN"));
        OneEN->setGeometry(QRect(5, 45, 60, 50));
        OneEN->setFocusPolicy(Qt::NoFocus);
        OneEN->setStyleSheet(QString::fromUtf8("QPushButton{outline: none; border-radius: 5px; font-weight: bold; font-size: 18px; color: rgb(25, 25, 112); background-color:rgb(171, 223, 245); } QPushButton:pressed{background-color: rgb(25, 25, 112) ; color: white;}"));
        Char2 = new QPushButton(frameEnKeyBord);
        Char2->setObjectName(QString::fromUtf8("Char2"));
        Char2->setGeometry(QRect(135, 210, 60, 50));
        Char2->setFocusPolicy(Qt::NoFocus);
        Char2->setStyleSheet(QString::fromUtf8("QPushButton{outline: none; border-radius: 5px; font-weight: bold; font-size: 23px; color: rgb(25, 25, 112); background-color:rgb(171, 223, 245); } QPushButton:pressed{background-color: rgb(25, 25, 112) ; color: white;}"));
        Char3 = new QPushButton(frameEnKeyBord);
        Char3->setObjectName(QString::fromUtf8("Char3"));
        Char3->setGeometry(QRect(70, 265, 60, 50));
        Char3->setFocusPolicy(Qt::NoFocus);
        Char3->setStyleSheet(QString::fromUtf8("QPushButton{outline: none; border-radius: 5px; font-weight: bold; font-size: 23px; color: rgb(25, 25, 112); background-color:rgb(171, 223, 245); } QPushButton:pressed{background-color: rgb(25, 25, 112) ; color: white;}"));
        FourEN = new QPushButton(frameEnKeyBord);
        FourEN->setObjectName(QString::fromUtf8("FourEN"));
        FourEN->setGeometry(QRect(5, 100, 60, 50));
        FourEN->setFocusPolicy(Qt::NoFocus);
        FourEN->setStyleSheet(QString::fromUtf8("QPushButton{outline: none; border-radius: 5px; font-weight: bold; font-size: 18px; color: rgb(25, 25, 112); background-color:rgb(171, 223, 245); } QPushButton:pressed{background-color: rgb(25, 25, 112) ; color: white;}"));
        NineEN = new QPushButton(frameEnKeyBord);
        NineEN->setObjectName(QString::fromUtf8("NineEN"));
        NineEN->setGeometry(QRect(135, 155, 60, 50));
        NineEN->setFocusPolicy(Qt::NoFocus);
        NineEN->setStyleSheet(QString::fromUtf8("QPushButton{outline: none; border-radius: 5px; font-weight: bold; font-size: 18px; color: rgb(25, 25, 112); background-color:rgb(171, 223, 245); } QPushButton:pressed{background-color: rgb(25, 25, 112) ; color: white;}"));
        SixEN = new QPushButton(frameEnKeyBord);
        SixEN->setObjectName(QString::fromUtf8("SixEN"));
        SixEN->setGeometry(QRect(135, 100, 60, 50));
        SixEN->setFocusPolicy(Qt::NoFocus);
        SixEN->setStyleSheet(QString::fromUtf8("QPushButton{outline: none; border-radius: 5px; font-weight: bold; font-size: 18px; color: rgb(25, 25, 112); background-color:rgb(171, 223, 245); } QPushButton:pressed{background-color: rgb(25, 25, 112) ; color: white;}"));
        ShowEN = new QLabel(frameEnKeyBord);
        ShowEN->setObjectName(QString::fromUtf8("ShowEN"));
        ShowEN->setGeometry(QRect(10, 9, 180, 31));
        ShowEN->setStyleSheet(QString::fromUtf8("font-size: 23px; color: rgb(25, 25, 112);"));
        ShowEN->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 665, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "1\n"
"abc", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        EightEN->setText(QApplication::translate("MainWindow", "8\n"
"stu", 0, QApplication::UnicodeUTF8));
        TowEN->setText(QApplication::translate("MainWindow", "2\n"
"abc", 0, QApplication::UnicodeUTF8));
        Char1->setText(QApplication::translate("MainWindow", ":", 0, QApplication::UnicodeUTF8));
        RemoveAll->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", 0, QApplication::UnicodeUTF8));
        Remove->setText(QApplication::translate("MainWindow", "\351\200\200\346\240\274", 0, QApplication::UnicodeUTF8));
        FiveEN->setText(QApplication::translate("MainWindow", "5\n"
"jkl", 0, QApplication::UnicodeUTF8));
        SevenEN->setText(QApplication::translate("MainWindow", "7\n"
"pqr", 0, QApplication::UnicodeUTF8));
        ZeroEN->setText(QApplication::translate("MainWindow", "0\n"
"yz", 0, QApplication::UnicodeUTF8));
        ThreeEN->setText(QApplication::translate("MainWindow", "3\n"
"def", 0, QApplication::UnicodeUTF8));
        OneEN->setText(QApplication::translate("MainWindow", "1\n"
"@/", 0, QApplication::UnicodeUTF8));
        Char2->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        Char3->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        FourEN->setText(QApplication::translate("MainWindow", "4\n"
"ghi", 0, QApplication::UnicodeUTF8));
        NineEN->setText(QApplication::translate("MainWindow", "9\n"
"vwx", 0, QApplication::UnicodeUTF8));
        SixEN->setText(QApplication::translate("MainWindow", "6\n"
"mno", 0, QApplication::UnicodeUTF8));
        ShowEN->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
