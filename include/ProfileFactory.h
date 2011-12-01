#ifndef PROFILFACTORY_H
#define PROFILFACTORY_H

#include "Entities/Ship.h"
#include "Entities/Shuriken.h"
#include "Entities/GreenSquare.h"
#include "Entities/Spaceship.h"
#include "Entities/Fire01.h"
#include "Entities/GameDelimiterUp.h"
#include "Entities/GameDelimiterDown.h"
#include "Entities/GameDelimiterLeft.h"
#include "Entities/GameDelimiterRight.h"
#include "Registry.h"
#include <QMap>

class MoveBehavior;
class ShootBehavior;
class RotationBehavior;
class TransformationBehavior;

class RotationBehaviorFactory : public Registry<RotationBehavior>::listener
{
protected:
    void registered(const Registry<RotationBehavior>::entry &e) {
        qDebug() << "New entity available: " << e.getName();
    }

public:
    RotationBehaviorFactory() { init(); }  // Print those already registered.
    static RotationBehavior *getRotationBehavior(const char *name);
    static RotationBehavior *getRandom(int, Entity *);
};

extern RotationBehaviorFactory rotationBehaviorFactory;



class ShootBehaviorFactory : public Registry<ShootBehavior>::listener
{
protected:
    void registered(const Registry<ShootBehavior>::entry &e) {
        qDebug() << "New entity available: " << e.getName();
    }

public:
    ShootBehaviorFactory() { init(); }  // Print those already registered.
    static ShootBehavior *getShootBehavior(const char *name);
    static ShootBehavior *getRandom(int);
};

extern ShootBehaviorFactory shootBehaviorFactory;



class TransformationBehaviorFactory : public Registry<TransformationBehavior>::listener
{
protected:
    void registered(const Registry<TransformationBehavior>::entry &e) {
        qDebug() << "New entity available: " << e.getName();
    }

public:
    TransformationBehaviorFactory() { init(); }  // Print those already registered.
    static TransformationBehavior *getTransformationBehavior(const char *name);
    static TransformationBehavior *getRandom(int);
};

extern TransformationBehaviorFactory transformationBehaviorFactory;



class MoveBehaviorFactory : public Registry<MoveBehavior>::listener
{
protected:
    void registered(const Registry<MoveBehavior>::entry &e) {
        qDebug() << "New entity available: " << e.getName();
    }

public:
    MoveBehaviorFactory() { init(); }  // Print those already registered.
    static MoveBehavior *getMoveBehavior(const char *name);
    static MoveBehavior *getRandom(int, Entity *);
};

extern MoveBehaviorFactory moveBehaviorFactory;

#endif // ENTITYFACTORY_H
