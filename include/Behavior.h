#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "Entity.h"
#include <QEvent>

class Behavior
{
public:
    virtual void behave(Entity*) = 0;
    virtual void keyPressEvent( QKeyEvent * event ) = 0;
    virtual void keyReleaseEvent( QKeyEvent * event ) = 0;
};

#endif // BEHAVIOR_H
