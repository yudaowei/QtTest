#ifndef CITYBLOCK_H
#define CITYBLOCK_H

#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <math.h>

class CityBlock : public QGraphicsItem
{
public:
    enum Kind{Park, SmallBuilding, Hospital, Hall, Building, Tower,
              LShapedBlock, LShapedBlockPlusSmallBlock, TwoBlocks,
              BlockPlusTwoSmallBlocks};
    CityBlock(Kind king);

    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *);

private:
    int kind;
    QColor color;
    QPainterPath shape;
};

#endif // CITYBLOCK_H
