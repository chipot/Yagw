#ifndef LFOLLOWINGROTATIONBEHAVIOR_H
#define LFOLLOWINGROTATIONBEHAVIOR_H

#include <QtCore/qmath.h>
#include "Behaviors.h"

class SimpleRotationBehavior : public RotationBehavior
{
protected :
    int angle;
public :
    SimpleRotationBehavior(Entity *ent = 0, Entity *t = 0, int a = 0) : RotationBehavior(ent, t), angle(a) {}
    void rotate();
    void init();
    SimpleRotationBehavior *copy() const;
};

#endif // FOLLOWINGROTATIONBEHAVIOR_H
