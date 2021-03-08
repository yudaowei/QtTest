#include "node.h"

Node::Node()
{
    myTextColor = Qt::darkGreen;
    myOutlineColor = Qt::darkBlue;
    myBackgroundColor = Qt::white;

    setFlags(ItemIsMovable | ItemSendsGeometryChanges | ItemIsSelectable);
}
Node::~Node()
{
    foreach(Link *link, myLinks)
        delete link;
}
QString Node::text() const
{
    return myText;
}
QColor Node::textColor() const
{
    return myTextColor;
}
QColor Node::outlineColor() const
{
    return myOutlineColor;
}
QColor Node::backgroundColor() const
{
    return myBackgroundColor;
}
void Node::setText(const QString &text)
{
    prepareGeometryChange();//为几何图形更改准备项目。在更改项的边界矩形之前调用此函数，以使QGraphicsScene的索引保持最新。
    myText = text;
    update();
}
void Node::setTextColor(const QColor &color)
{
    myTextColor = color;
    update();
}
void Node::setOutlineColor(const QColor &color)
{
    myOutlineColor = color;
    update();
}
void Node::setBackgroundColor(const QColor &color)
{
    myBackgroundColor = color;
    update();
}
void Node::addLink(Link *link)
{
    myLinks.insert(link);
}
void Node::removeLink(Link *link)
{
    myLinks.remove(link);
}
QRectF Node::outlineRect() const//返回字体规格矩形
{
    const int Padding = 8;
    QFontMetricsF metrics = qApp->fontMetrics();
    QRectF rect = metrics.boundingRect(myText);
    rect.adjust(-Padding, -Padding, +Padding, +Padding);//修改原来的矩形 调整节点内字体占用多少像素留白
    rect.translate(-rect.center());
    return rect;
}
QRectF Node::boundingRect() const
{
    const int Margin = 1;
    return outlineRect().adjusted(-Margin, -Margin, +Margin, +Margin);//返回一个新的矩形
}
QPainterPath Node::shape() const//由视图QGraphicsView调用,用来做精确的碰撞检测,即鼠标点击是否在范围内
{
    QRectF rect = outlineRect();
    QPainterPath path;
    path.addRoundedRect(rect, roundness(rect.width()), roundness(rect.height()));
    return path;//该对象代表一个圆角矩形
}
void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    QPen pen(myOutlineColor);
    if(option->state & QStyle::State_Selected){//如果项被选中
        pen.setStyle(Qt::DotLine);//虚线风格
        pen.setWidth(2);//宽度变粗
    }
    painter->setPen(pen);
    painter->setBrush(myBackgroundColor);

    QRectF rect = outlineRect();
    painter->drawRoundedRect(rect, roundness(rect.width()),
                             roundness(rect.height()));//绘制圆角矩形

    painter->setPen(myTextColor);
    painter->drawText(rect, Qt::AlignCenter, myText);
}
QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if(change == ItemPositionHasChanged){//项坐标改变
        foreach(Link *link, myLinks)
            link->trackNodes();//重新连接线
    }
    return QGraphicsItem::itemChange(change, value);//传给父类,确保父类也得到通知
}
void Node::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QString text = QInputDialog::getText(event->widget(),
                                         tr("Edit Text"), tr("Enter new text:"),
                                         QLineEdit::Normal, myText);//弹出对话框,点击cancel返回一个空的字符串
    if(!text.isEmpty())
        setText(text);
}
int Node::roundness(double size) const//返回圆角率
{
    const int Diameter = 12;
    return 100 * Diameter / int(size);
}
