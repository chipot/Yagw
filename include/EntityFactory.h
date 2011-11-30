#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "Entities/Ship.h"
#include "Entities/Shuriken.h"
#include "Entities/GreenSquare.h"
#include "Entities/Spaceship.h"
#include "Entities/Fire01.h"
#include "Entities/GameDelimiterUp.h"
#include "Entities/GameDelimiterDown.h"
#include "Entities/GameDelimiterLeft.h"
#include "Entities/GameDelimiterRight.h"
#include "FireBehavior.h"
#include "Registry.h"
#include <QMap>

class EntityFactory : public Registry<Entity>::listener
{
protected:
    void registered(const Registry<Entity>::entry &e) {
        qDebug() << "New entity available: " << e.getName();
    }

public:
    EntityFactory() { init(); }  // Print those already registered.
    static Entity *getEntity(const char *name);
    static Entity *getRandom(int);
};

extern EntityFactory Factory;

#endif // ENTITYFACTORY_H
