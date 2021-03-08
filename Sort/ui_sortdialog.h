/********************************************************************************
** Form generated from reading UI file 'sortdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTDIALOG_H
#define UI_SORTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_SortDialog
{
public:
    QPushButton *okButton;
    QPushButton *cancelButton;
    QPushButton *moreButton;
    QGroupBox *primaryGroupBox;
    QGridLayout *gridLayout;
    QLabel *orderlabel;
    QComboBox *primaryColumnCombo;
    QLabel *columnLabel;
    QComboBox *primaryOrderCombo;
    QSpacerItem *horizontalSpacer;
    QGroupBox *secondaryGroupBox;
    QGridLayout *gridLayout_2;
    QComboBox *secondaryColumnCombo;
    QLabel *orderlabel_2;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *secondaryOrderCombo;
    QLabel *columnLabel_2;
    QGroupBox *tertiaryGroupBox;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *tertiaryOrderCombo;
    QLabel *columnLabel_3;
    QLabel *orderlabel_3;
    QComboBox *tertiaryColumncombo;

    void setupUi(QDialog *SortDialog)
    {
        if (SortDialog->objectName().isEmpty())
            SortDialog->setObjectName(QString::fromUtf8("SortDialog"));
        SortDialog->resize(315, 384);
        okButton = new QPushButton(SortDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(230, 10, 75, 23));
        okButton->setDefault(true);
        cancelButton = new QPushButton(SortDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(230, 39, 75, 23));
        moreButton = new QPushButton(SortDialog);
        moreButton->setObjectName(QString::fromUtf8("moreButton"));
        moreButton->setGeometry(QRect(230, 150, 75, 23));
        moreButton->setCheckable(true);
        primaryGroupBox = new QGroupBox(SortDialog);
        primaryGroupBox->setObjectName(QString::fromUtf8("primaryGroupBox"));
        primaryGroupBox->setGeometry(QRect(9, 9, 201, 81));
        gridLayout = new QGridLayout(primaryGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        orderlabel = new QLabel(primaryGroupBox);
        orderlabel->setObjectName(QString::fromUtf8("orderlabel"));
        orderlabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(orderlabel, 1, 0, 1, 1);

        primaryColumnCombo = new QComboBox(primaryGroupBox);
        primaryColumnCombo->setObjectName(QString::fromUtf8("primaryColumnCombo"));

        gridLayout->addWidget(primaryColumnCombo, 0, 1, 1, 1);

        columnLabel = new QLabel(primaryGroupBox);
        columnLabel->setObjectName(QString::fromUtf8("columnLabel"));
        columnLabel->setTextFormat(Qt::AutoText);
        columnLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(columnLabel, 0, 0, 1, 1);

        primaryOrderCombo = new QComboBox(primaryGroupBox);
        primaryOrderCombo->setObjectName(QString::fromUtf8("primaryOrderCombo"));

        gridLayout->addWidget(primaryOrderCombo, 1, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(61, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        secondaryGroupBox = new QGroupBox(SortDialog);
        secondaryGroupBox->setObjectName(QString::fromUtf8("secondaryGroupBox"));
        secondaryGroupBox->setGeometry(QRect(10, 180, 201, 78));
        gridLayout_2 = new QGridLayout(secondaryGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        secondaryColumnCombo = new QComboBox(secondaryGroupBox);
        secondaryColumnCombo->setObjectName(QString::fromUtf8("secondaryColumnCombo"));

        gridLayout_2->addWidget(secondaryColumnCombo, 0, 1, 1, 1);

        orderlabel_2 = new QLabel(secondaryGroupBox);
        orderlabel_2->setObjectName(QString::fromUtf8("orderlabel_2"));
        orderlabel_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(orderlabel_2, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(28, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        secondaryOrderCombo = new QComboBox(secondaryGroupBox);
        secondaryOrderCombo->setObjectName(QString::fromUtf8("secondaryOrderCombo"));

        gridLayout_2->addWidget(secondaryOrderCombo, 1, 1, 1, 2);

        columnLabel_2 = new QLabel(secondaryGroupBox);
        columnLabel_2->setObjectName(QString::fromUtf8("columnLabel_2"));
        columnLabel_2->setTextFormat(Qt::AutoText);
        columnLabel_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(columnLabel_2, 0, 0, 1, 1);

        tertiaryGroupBox = new QGroupBox(SortDialog);
        tertiaryGroupBox->setObjectName(QString::fromUtf8("tertiaryGroupBox"));
        tertiaryGroupBox->setGeometry(QRect(9, 267, 201, 78));
        gridLayout_3 = new QGridLayout(tertiaryGroupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(80, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        tertiaryOrderCombo = new QComboBox(tertiaryGroupBox);
        tertiaryOrderCombo->setObjectName(QString::fromUtf8("tertiaryOrderCombo"));

        gridLayout_3->addWidget(tertiaryOrderCombo, 1, 1, 1, 2);

        columnLabel_3 = new QLabel(tertiaryGroupBox);
        columnLabel_3->setObjectName(QString::fromUtf8("columnLabel_3"));
        columnLabel_3->setTextFormat(Qt::AutoText);
        columnLabel_3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(columnLabel_3, 0, 0, 1, 1);

        orderlabel_3 = new QLabel(tertiaryGroupBox);
        orderlabel_3->setObjectName(QString::fromUtf8("orderlabel_3"));
        orderlabel_3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(orderlabel_3, 1, 0, 1, 1);

        tertiaryColumncombo = new QComboBox(tertiaryGroupBox);
        tertiaryColumncombo->setObjectName(QString::fromUtf8("tertiaryColumncombo"));

        gridLayout_3->addWidget(tertiaryColumncombo, 0, 1, 1, 1);

        QWidget::setTabOrder(primaryColumnCombo, primaryOrderCombo);
        QWidget::setTabOrder(primaryOrderCombo, secondaryColumnCombo);
        QWidget::setTabOrder(secondaryColumnCombo, secondaryOrderCombo);
        QWidget::setTabOrder(secondaryOrderCombo, tertiaryColumncombo);
        QWidget::setTabOrder(tertiaryColumncombo, tertiaryOrderCombo);
        QWidget::setTabOrder(tertiaryOrderCombo, okButton);
        QWidget::setTabOrder(okButton, cancelButton);
        QWidget::setTabOrder(cancelButton, moreButton);

        retranslateUi(SortDialog);
        QObject::connect(okButton, SIGNAL(clicked()), SortDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), SortDialog, SLOT(reject()));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), secondaryGroupBox, SLOT(setVisible(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), tertiaryGroupBox, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(SortDialog);
    } // setupUi

    void retranslateUi(QDialog *SortDialog)
    {
        SortDialog->setWindowTitle(QApplication::translate("SortDialog", "Sort", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("SortDialog", "OK", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("SortDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        moreButton->setText(QApplication::translate("SortDialog", "&More", 0, QApplication::UnicodeUTF8));
        primaryGroupBox->setTitle(QApplication::translate("SortDialog", "&Primary Key", 0, QApplication::UnicodeUTF8));
        orderlabel->setText(QApplication::translate("SortDialog", "Order", 0, QApplication::UnicodeUTF8));
        primaryColumnCombo->clear();
        primaryColumnCombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "None", 0, QApplication::UnicodeUTF8)
        );
        columnLabel->setText(QApplication::translate("SortDialog", "Column", 0, QApplication::UnicodeUTF8));
        primaryOrderCombo->clear();
        primaryOrderCombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "Ascending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SortDialog", "Descending", 0, QApplication::UnicodeUTF8)
        );
        secondaryGroupBox->setTitle(QApplication::translate("SortDialog", "&Secondary Key", 0, QApplication::UnicodeUTF8));
        secondaryColumnCombo->clear();
        secondaryColumnCombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "None", 0, QApplication::UnicodeUTF8)
        );
        orderlabel_2->setText(QApplication::translate("SortDialog", "Order", 0, QApplication::UnicodeUTF8));
        secondaryOrderCombo->clear();
        secondaryOrderCombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "Ascending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SortDialog", "Descending", 0, QApplication::UnicodeUTF8)
        );
        columnLabel_2->setText(QApplication::translate("SortDialog", "Column", 0, QApplication::UnicodeUTF8));
        tertiaryGroupBox->setTitle(QApplication::translate("SortDialog", "&Tertiary Key", 0, QApplication::UnicodeUTF8));
        tertiaryOrderCombo->clear();
        tertiaryOrderCombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "Ascending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SortDialog", "Descending", 0, QApplication::UnicodeUTF8)
        );
        columnLabel_3->setText(QApplication::translate("SortDialog", "Column", 0, QApplication::UnicodeUTF8));
        orderlabel_3->setText(QApplication::translate("SortDialog", "Order", 0, QApplication::UnicodeUTF8));
        tertiaryColumncombo->clear();
        tertiaryColumncombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "None", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class SortDialog: public Ui_SortDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTDIALOG_H
