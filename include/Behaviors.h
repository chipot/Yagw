#ifndef BEHAVIORS_H
#define BEHAVIORS_H


#include <QVector2D>
#include <QTime>
#include "Behavior.h"

class MoveBehavior : public Behavior
{
public :
    MoveBehavior() : time(QTime()), target(0) {time.start();}
    virtual ~MoveBehavior(){}
    virtual void move() = 0;
    virtual void behave(Entity*){}
    virtual QPointF calcMove(QPointF direction, int speed) {
            float dist = speed * (float)(time.elapsed()/1000.0);
            QVector2D vector(direction);
            vector.normalize();
            time.restart();
            return (QPointF(vector.x(), vector.y())* dist);
    }
    void setTarget(Entity*e){target = e;}
protected :
    QTime time;
    Entity *target;

};

class ShootBehavior : public Behavior {
public :
    ShootBehavior(){}
    virtual ~ShootBehavior(){}
    virtual void shoot() = 0;
    virtual void behave(Entity*){}

};

class RotationBehavior : public Behavior {
public :
    RotationBehavior():target(0){}
    virtual ~RotationBehavior(){}
    virtual void rotate() = 0;
    virtual void behave(Entity*){}
    void setTarget(Entity*e){target = e;}
  protected:
    Entity *target;
};

class TransformationBehavior : public Behavior {
public :
    TransformationBehavior(){}
    virtual ~TransformationBehavior(){}
    virtual void transform() = 0;
    virtual void behave(Entity*){}
};

class CollisionBehavior : public Behavior {
public :
    CollisionBehavior(){}
    virtual ~CollisionBehavior(){}
    virtual void collide() = 0;
};

#endif // BEHAVIORS_H
