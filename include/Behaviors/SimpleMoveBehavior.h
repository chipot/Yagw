#ifndef SIMPLEFIREBEHAVIOR_H
#define SIMPLEFIREBEHAVIOR_H

#include "Behaviors.h"

class SimpleMoveBehavior : public MoveBehavior
{
private:
    QPointF direction;
    int speed;

    public :
        SimpleMoveBehavior(QPointF dir = QPointF(0,0), int speed = 100);
        ~SimpleMoveBehavior(){}
        void setDirection(QPointF dir);
        void move();
        void init();
};

#endif // SIMPLEFIREBEHAVIOR_H
