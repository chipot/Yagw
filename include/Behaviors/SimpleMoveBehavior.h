#ifndef SIMPLEFIREBEHAVIOR_H
#define SIMPLEFIREBEHAVIOR_H

#include "Behaviors.h"

class SimpleMoveBehavior : public MoveBehavior
{
private:
    QPointF direction;

    public :
        SimpleMoveBehavior(QPointF dir = QPointF(0,0));
        ~SimpleMoveBehavior(){}
        void setDirection(QPointF dir);
        void move();
};

#endif // SIMPLEFIREBEHAVIOR_H
