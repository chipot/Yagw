#ifndef BASICFOLLOWINGBEHAVIOR_H
#define BASICFOLLOWINGBEHAVIOR_H


#include <QVector2D>
#include "Behaviors.h"


class BasicFollowingBehavior : public MoveBehavior
{
private :

public :
    BasicFollowingBehavior(Entity *ent = 0){ entity = ent;}
    void move();
    void init();
    static QPointF calcDirection(QPointF, QPointF);

protected :
};

#endif // BASICFOLLOWINGBEHAVIOR_H
