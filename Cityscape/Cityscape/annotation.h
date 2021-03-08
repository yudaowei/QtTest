#ifndef ANNOTATION_H
#define ANNOTATION_H

#include <QGraphicsItem>
#include <QApplication>
#include <QFont>
#include <QFontMetricsF>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <math.h>
#include <QDebug>

class Annotation : public QGraphicsItem
{
public:
    Annotation(const QString &text, bool major = false);

    void setText(const QString &text);
    QString text() const;

    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QFont font;
    QString str;
    bool major;
    double threshold;
    int y;
};

#endif // ANNOTATION_H
