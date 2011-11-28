#ifndef WALLFIREBEHAVIOR_H
#define WALLFIREBEHAVIOR_H

#include "Behavior.h"
#include <QPointF>

class WallBehavior : public Behavior
{
private :
    QPointF direction;
public:
    WallBehavior();
    void behave(Entity*);
    void setDirection(QPointF dir);
    void setRotationSpeed(int);
};

#endif // FIREBEHAVIOR_H
