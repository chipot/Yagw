#ifndef FOLLOWINGROTATIONBEHAVIOR_H
#define FOLLOWINGROTATIONBEHAVIOR_H

#include <QtCore/qmath.h>
#include "Behaviors.h"

class FollowingRotationBehavior : public RotationBehavior
{
protected :
    int angle;
public :
    FollowingRotationBehavior(Entity *ent = 0, Entity *t = 0, int a = 0) : RotationBehavior(ent, t), angle(a) {}
    void rotate();
    void init();
    FollowingRotationBehavior *copy() const;
};

#endif // FOLLOWINGROTATIONBEHAVIOR_H
