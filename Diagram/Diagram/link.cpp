#include "link.h"

Link::Link(Node *fromNode, Node *toNode)
{
    myFromNode = fromNode;
    myToNode = toNode;

    myFromNode->addLink(this);// 节点增加连线，每个节点有任意多个连线
    myToNode->addLink(this);

    setFlags(QGraphicsItem::ItemIsSelectable);// 连线可以被选择，然后删除
    setZValue(-1);// 在场景中显示的前后层次，因为连线是两个节点的中心，-1表示位于最后面，
// 节点覆盖了部分连线
    setColor(Qt::darkRed);
    trackNodes();
}

Link::~Link()
{
    myFromNode->removeLink(this);//删除连线节点
    myToNode->removeLink(this);
}

void Link::setColor(const QColor &color)
{
    setPen(QPen(color, 1.0));
}

void Link::trackNodes()
{
    setLine(QLineF(myFromNode->pos(), myToNode->pos()));
}
Node *Link::fromNode() const
{
    return myFromNode;
}

Node *Link::toNode() const
{
    return myToNode;
}
QColor Link::color() const
{
    return pen().color();
}
