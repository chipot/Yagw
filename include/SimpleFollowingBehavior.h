#ifndef SIMPLEFOLLOWINGBEHAVIOR_H
#define SIMPLEFOLLOWINGBEHAVIOR_H

#include "EnnemyBehavior.h"

class SimpleFollowingBehavior : public EnnemyBehavior
{
public :
    SimpleFollowingBehavior();
    virtual ~SimpleFollowingBehavior(){}
    void behave(Entity *entity);
};


class FollowingPacmanBehavior : public SimpleFollowingBehavior
{
public :
    FollowingPacmanBehavior();
    virtual ~FollowingPacmanBehavior(){}
    void behave(Entity *entity);
};

#endif // SIMPLEFOLLOWINGBEHAVIOR_H
