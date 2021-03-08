#ifndef NODE_H
#define NODE_H

#include <QGraphicsLineItem>
#include <QSet>
#include <QFontMetricsF>
#include <QApplication>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QInputDialog>
#include <QGraphicsSceneMouseEvent>
#include "link.h"
#include <QVariant>
class Link;
class Node : public QGraphicsItem
{
    Q_DECLARE_TR_FUNCTIONS(Node)//用来给类添加一个tr()函数
public:
    Node();
    ~Node();

    void setText(const QString &text);
    QString text() const;
    void setTextColor(const QColor &color);
    QColor textColor() const;
    void setOutlineColor(const QColor &color);
    QColor outlineColor() const;
    void setBackgroundColor(const QColor &color);
    QColor backgroundColor() const;

    void addLink(Link *link);
    void removeLink(Link *link);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //想要自己绘图一般重新实现这三个函数
protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);//每当属性改变时调用,如节点移动

private:
    QRectF outlineRect() const;//返回节点绘制的矩形
    int roundness(double size) const;//返回基于矩形宽度和高度的合适的圆度系数

    QSet<Link *> myLinks;//QSet是一个基于哈希表的集合
    QString myText;
    QColor myTextColor;
    QColor myBackgroundColor;
    QColor myOutlineColor;
    
};

#endif // NODE_H
