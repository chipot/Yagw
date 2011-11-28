#ifndef SIMPLEFOLLOWINGBEHAVIOR_H
#define SIMPLEFOLLOWINGBEHAVIOR_H


#include <QVector2D>
#include "Behaviors.h"

class BasicFollowingBehavior : public MoveBehavior
{
private :

public :
    BasicFollowingBehavior(Entity *ent, Entity *entToFollow = 0) : entity(ent), entityToFollow(entToFollow){}
    void move();
    static QPointF calcDirection(QPointF, QPointF);

protected :
    Entity *entityToFollow;
    Entity *entity;

};

#endif // SIMPLEFOLLOWINGBEHAVIOR_H
