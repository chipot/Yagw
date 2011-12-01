#ifndef FIRE_H
#define FIRE_H

#include "Entity.h"

class Shuriken : public Entity
{
private :
    // private methods
    void initPath();

public:
    Shuriken();
    virtual ~Shuriken(){}
//    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
};


#endif // FIRE_H
