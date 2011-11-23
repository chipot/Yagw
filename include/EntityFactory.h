#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "Ship.h"
#include "Shuriken.h"
#include "GreenSquare.h"
#include "FireBehavior.h"
#include "Registry.h"
#include <QMap>

class EntityFactory : public Registry<Entity>::listener
{
protected:
    void registered(const Registry<Entity>::entry &e) {
        qDebug() << "collector now available: " << e.getName() << "\n";
    }

public:
    EntityFactory() { init(); }  // Print those already registered.
    static Entity *getEntity(const char *name);
};

extern EntityFactory Factory;

#endif // ENTITYFACTORY_H
