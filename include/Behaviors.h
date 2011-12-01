#ifndef BEHAVIORS_H
#define BEHAVIORS_H


#include <QVector2D>
#include <QTime>
#include "Behavior.h"

class MoveBehavior : public Behavior
{
protected :
    QTime time;
    Entity *target;
public :
    MoveBehavior(Entity *ent = 0, Entity *t = 0) : Behavior(ent), time(QTime()), target(t) {time.start();}
    virtual ~MoveBehavior(){}
    virtual void move() = 0;
    void setTarget(Entity *t) {target = t;}
    virtual MoveBehavior *copy(){qDebug() << "move behavior copy";  return 0;}
    virtual void print(){}
};

class ShootBehavior : public Behavior {
public :
    ShootBehavior(){}
    virtual ~ShootBehavior(){}
    virtual void shoot() = 0;
    virtual ShootBehavior *copy()  {return 0;}
};

class RotationBehavior : public Behavior {
protected :
    Entity *target;
public :
    RotationBehavior(Entity *ent = 0, Entity *t = 0) : Behavior(ent), target(t) {}
    virtual ~RotationBehavior(){}
    virtual void rotate() = 0;
    void setTarget(Entity *t) {target = t;}
    virtual RotationBehavior *copy() {return 0;}
};

class TransformationBehavior : public Behavior {
public :
    TransformationBehavior(){}
    virtual ~TransformationBehavior(){}
    virtual void transform() = 0;
    virtual TransformationBehavior *copy() {qDebug() << "transformation behavior.";return 0; }
};

class CollisionBehavior : public Behavior {
public :
    CollisionBehavior(){}
    virtual ~CollisionBehavior(){}
    virtual void collide() = 0;
};

#endif // BEHAVIORS_H
