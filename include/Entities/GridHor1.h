#ifndef GRIDHOR1_H
#define GRIDHOR1_H

#include "Entity.h"

class GridHor1 : public Entity
{

private:
    void initPath();

public:
    GridHor1();
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
};

#endif // GRIDHOR1_H
