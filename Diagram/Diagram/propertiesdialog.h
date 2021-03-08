#ifndef PROPERTIESDIALOG_H
#define PROPERTIESDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QColorDialog>
#include "node.h"
class Node;
namespace Ui {
class Propertiesdialog;
}

class Propertiesdialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Propertiesdialog(Node *node, QWidget *parent = 0);
    ~Propertiesdialog();
    

private slots:
    void on_buttonBox_accepted();    // 快速信号连接
    void on_textColorButton_clicked();
    void on_outlineColorButton_clicked();
    void on_backgroundColorButton_clicked();

private:
    Ui::Propertiesdialog *ui;
    void updateColorLabel(QLabel *label, const QColor &color);
    void chooseColor(QLabel *label, QColor *color);

    Node *node;
    QColor textColor;
    QColor outlineColor;
    QColor backgroundColor;
};

#endif // PROPERTIESDIALOG_H
