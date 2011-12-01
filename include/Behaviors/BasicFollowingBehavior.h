#ifndef BASICFOLLOWINGBEHAVIOR_H
#define BASICFOLLOWINGBEHAVIOR_H


#include <QVector2D>
#include "Behaviors.h"


class BasicFollowingBehavior : public MoveBehavior
{
protected :
    int speed;

public :
    BasicFollowingBehavior(Entity *ent = 0, Entity *t = 0, int moveSpeed = 100) : MoveBehavior(ent, t), speed(moveSpeed) {}
    void move();
    void init();
    virtual BasicFollowingBehavior *copy();
};

#endif // BASICFOLLOWINGBEHAVIOR_H
