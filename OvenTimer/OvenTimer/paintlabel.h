#ifndef PAINTLABEL_H
#define PAINTLABEL_H

#include <QLabel>
#include <QPainter>

class paintLabel : public QLabel
{
    Q_OBJECT
public:
    explicit paintLabel(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *event);
signals:
    
public slots:
    
};

#endif // PAINTLABEL_H
