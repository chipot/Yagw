#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Entity.h"

class Spaceship : public Entity
{

private:
    void initPath();

public:
    Spaceship();
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
};

#endif // SPACESHIP_H
