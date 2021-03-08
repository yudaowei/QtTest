#include "sortdialog.h"
SortDialog::SortDialog(QWidget *parent)
	:QDialog(parent)
{
	setupUi(this);
	
	secondaryGroupBox->hide();
	tertiaryGroupBox->hide();
	layout()->setSizeConstraint(QLayout::SetFixedSize);//设置该窗体无法修改大小
	
	setColumnRange('A', 'Z');
	
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
	primaryColumnCombo->clear();
    secondaryColumnCombo->clear();
    tertiaryColumncombo->clear();

    primaryColumnCombo->addItem(tr("None"));
    tertiaryColumncombo->addItem(tr("None"));
	primaryColumnCombo->setMinimumSize(secondaryColumnCombo->sizeHint());
	
    QChar ch = first;
	while(ch <= last)
	{
        primaryColumnCombo->addItem(QString(ch));
        secondaryColumnCombo->addItem(QString(ch));
        tertiaryColumncombo->addItem(QString(ch));
        ch = ch.unicode() + 1;//ASCII码值+1
	}
}
