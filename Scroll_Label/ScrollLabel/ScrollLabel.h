#ifndef SCROLLLABEL_H
#define SCROLLLABEL_H


#include <QLabel>
#include <QPainter>
#include <QTimerEvent>
#include <QTimer>
#include <QDebug>
#include <QTextCodec>
#include <QApplication>
#include <QFontMetrics>
#include <QDebug>
#include <QString>
class ScrollLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ScrollLabel(QWidget *parent = 0, Qt::WindowFlags f=0);

signals:
    void currentTextChanged();

public slots:
    void mysetText(const QString &);

protected:
    void showEvent(QShowEvent *);
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void hideEvent(QHideEvent *);

private slots:
    void metrics();
    void startScroll();

private:
    QString mystring;
    int getHeight();
    int offset;
    int timerID;
    int textHeight;

};


#endif // SCROLLLABEL_H
