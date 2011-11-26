#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "Entity.h"
#include <QEvent>

class Behavior
{
  public:
    Behavior(){}
    virtual ~Behavior(){}
    virtual void behave(Entity*) = 0;
  protected:
    int angle;
    int rotationSpeed;
    int moveSpeed;
};

#endif // BEHAVIOR_H
