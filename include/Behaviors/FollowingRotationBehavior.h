#ifndef FOLLOWINGROTATIONBEHAVIOR_H
#define FOLLOWINGROTATIONBEHAVIOR_H

#include <QtCore/qmath.h>
#include "Behaviors.h"

class FollowingRotationBehavior : public RotationBehavior
{
public :
    FollowingRotationBehavior(Entity *ent = 0, Entity *entToFollow = 0, int angle = 0) : target(entToFollow), angle(angle) {entity = ent;}
    void rotate();
    void setTarget(Entity*);
    void init();
    static qreal calcAngle(QVector2D, QVector2D);

protected :
    Entity *target;
    int angle;

};

#endif // FOLLOWINGROTATIONBEHAVIOR_H
