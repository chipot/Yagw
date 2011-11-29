#ifndef BASICFOLLOWINGBEHAVIOR_H
#define BASICFOLLOWINGBEHAVIOR_H


#include <QVector2D>
#include "Behaviors.h"

class BasicFollowingBehavior : public MoveBehavior
{
private :

public :
    BasicFollowingBehavior(Entity *ent = 0, Entity *entToFollow = 0) : entity(ent), target(entToFollow){}
    void move();
    static QPointF calcDirection(QPointF, QPointF);
    void setTarget(Entity*);
    void init();

protected :
    Entity *entity;
    Entity *target;

};

#endif // BASICFOLLOWINGBEHAVIOR_H
