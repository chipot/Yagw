#ifndef FIREBEHAVIOR_H
#define FIREBEHAVIOR_H

#include "Behavior.h"
#include <QPointF>

class FireBehavior : public Behavior
{
private :
    QPointF direction;
public:
    FireBehavior();
    void behave(Entity*);
    void setDirection(QPointF dir);
    void setRotationSpeed(int);
};

#endif // FIREBEHAVIOR_H
