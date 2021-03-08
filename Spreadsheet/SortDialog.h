#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>

namespace Ui {
class SortDialog;
}

class SortDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SortDialog(QWidget *parent = 0);
    void setColumnRange(QChar first, QChar last);
    ~SortDialog();

//private:
    Ui::SortDialog *ui;
};

#endif // SORTDIALOG_H
