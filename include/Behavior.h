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
    void setEntity(Entity *ent) {this->entity = ent;}
    virtual void init(){}
  protected:
    Entity *entity;
};

#endif // BEHAVIOR_H
