#ifndef GRIDVERT1_H
#define GRIDVERT1_H

#include "Entity.h"

class GridVert1 : public Entity
{

private:
    void initPath();

public:
    GridVert1();
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
};

#endif // GRIDVERT1_H
