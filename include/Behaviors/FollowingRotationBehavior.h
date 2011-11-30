#ifndef FOLLOWINGROTATIONBEHAVIOR_H
#define FOLLOWINGROTATIONBEHAVIOR_H

#include <QtCore/qmath.h>
#include "Behaviors.h"

class FollowingRotationBehavior : public RotationBehavior
{
public :
    FollowingRotationBehavior(Entity *ent = 0, int angle = 0) : angle(angle) {entity = ent;}
    void rotate();
    void init();
    static qreal calcAngle(QVector2D, QVector2D);

protected :
    int angle;

};

#endif // FOLLOWINGROTATIONBEHAVIOR_H
