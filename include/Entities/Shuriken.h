#ifndef FIRE_H
#define FIRE_H

#include "Entity.h"

class Shuriken : public Entity
{
private :
    // private methods
    void initPath();
    QPointF direction;

public:
    Shuriken();
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    void setDirection(QPointF &direction);
};


#endif // FIRE_H
