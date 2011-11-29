#ifndef BASICFOLLOWINGBEHAVIOR_H
#define BASICFOLLOWINGBEHAVIOR_H


#include <QVector2D>
#include "Behaviors.h"

class BasicFollowingBehavior : public MoveBehavior
{
private :

public :
    BasicFollowingBehavior(Entity *ent = 0, Entity *entToFollow = 0) : target(entToFollow){ entity = ent;}
    void move();
    void setTarget(Entity*);
    void init();
    static QPointF calcDirection(QPointF, QPointF);

protected :
    Entity *target;
};

#endif // BASICFOLLOWINGBEHAVIOR_H
