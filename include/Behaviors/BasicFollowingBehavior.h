#ifndef BASICFOLLOWINGBEHAVIOR_H
#define BASICFOLLOWINGBEHAVIOR_H


#include <QVector2D>
#include "Behaviors.h"


class BasicFollowingBehavior : public MoveBehavior
{

public :
    BasicFollowingBehavior(Entity *ent = 0, Entity *t = 0) : MoveBehavior(ent, t) {}
    void move();
    void init();
    BasicFollowingBehavior *copy() const;
};

#endif // BASICFOLLOWINGBEHAVIOR_H
