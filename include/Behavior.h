#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "Entity.h"
#include <QEvent>

//class Entity;

class Behavior
{
  public:
    Behavior(Entity *ent = 0) : entity(ent) {}
    virtual ~Behavior(){}
    virtual void behave(Entity*) = 0;
    void setEntity(Entity *ent) {this->entity = ent;}
  protected:
    Entity *entity;
    int angle;
    int rotationSpeed;
    int moveSpeed;
};

#endif // BEHAVIOR_H
