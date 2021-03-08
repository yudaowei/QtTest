#include "SortDialog.h"
#include "ui_SortDialog.h"

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortDialog)
{
    ui->setupUi(this);
    ui->secondaryGroupBox->hide();
    ui->tertiaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);//设置该窗体无法修改大小

    setColumnRange('A', 'Z');

}
void SortDialog::setColumnRange(QChar first, QChar last)
{
    ui->primaryColumnCombo->clear();
    ui->secondaryColumnCombo->clear();
    ui->tertiaryColumncombo->clear();

    ui->primaryColumnCombo->addItem(tr("None"));
    ui->tertiaryColumncombo->addItem(tr("None"));
    ui->primaryColumnCombo->setMinimumSize(ui->secondaryColumnCombo->sizeHint());

    QChar ch = first;
    while(ch <= last)
    {
        ui->primaryColumnCombo->addItem(QString(ch));
        ui->secondaryColumnCombo->addItem(QString(ch));
        ui->tertiaryColumncombo->addItem(QString(ch));
        ch = ch.unicode() + 1;//ASCII码值+1
    }
}
SortDialog::~SortDialog()
{
    delete ui;
}
