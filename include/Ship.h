#ifndef SHIP_H
#define SHIP_H

#include "Entity.h"

class Ship : public Entity
{


private :
    // private methods
    void initPath();

public :
    Ship();
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
};

#endif // SHIP_H
