#include "propertiesdialog.h"
#include "ui_propertiesdialog.h"

Propertiesdialog::Propertiesdialog(Node *node, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Propertiesdialog)
{
    ui->setupUi(this);

    this->node = node;
    ui->xspinBox->setValue(int(node->x()));
    ui->yspinBox->setValue(int(node->y()));
    ui->textLineEdit->setText(node->text());
    textColor = node->textColor();
    outlineColor = node->outlineColor();
    backgroundColor = node->backgroundColor();

    updateColorLabel(ui->outlineColorLabel, outlineColor);
    updateColorLabel(ui->backgroundColorLabel, backgroundColor);
    updateColorLabel(ui->textColorLabel, textColor);
}
void Propertiesdialog::on_buttonBox_accepted()
{
    node->setPos(ui->xspinBox->value(), ui->yspinBox->value());
    node->setText(ui->textLineEdit->text());
    node->setOutlineColor(outlineColor);
    node->setBackgroundColor(backgroundColor);
    node->setTextColor(textColor);
    node->update();
    QDialog::accept();
}
void Propertiesdialog::on_textColorButton_clicked()
{
    chooseColor(ui->textColorLabel, &textColor);
}

void Propertiesdialog::on_outlineColorButton_clicked()
{
    chooseColor(ui->outlineColorLabel, &outlineColor);
}

void Propertiesdialog::on_backgroundColorButton_clicked()
{
    chooseColor(ui->backgroundColorLabel, &backgroundColor);
}

void Propertiesdialog::updateColorLabel(QLabel *label,
                                        const QColor &color)
{
    QPixmap pixmap(16, 16);
    pixmap.fill(color);
    label->setPixmap(pixmap);
}

void Propertiesdialog::chooseColor(QLabel *label, QColor *color)
{
    QColor newColor = QColorDialog::getColor(*color, this);
    if (newColor.isValid()) {
        *color = newColor;
        updateColorLabel(label, *color);
    }
}
Propertiesdialog::~Propertiesdialog()
{
    delete ui;
}
