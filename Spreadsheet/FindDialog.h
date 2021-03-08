#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>


class FindDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit FindDialog(QWidget *parent = 0);
    ~FindDialog();
signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);//大小写敏感性 取值有 Qt::CaseSensitive大小写敏感 Qt::Insensitive大小写不敏感
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
    void findClicked();
    void enableFindButton(const QString &text);

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwarCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;
};

#endif // FINDDIALOG_H
