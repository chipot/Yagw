#include "EntityFactory.h"

EntityFactory Factory;

Entity *EntityFactory::getEntity(const char *name) {
    Registry<Entity>::iterator it = Registry<Entity>::begin();
    Registry<Entity>::iterator ite = Registry<Entity>::end();
    for (;it != ite; ++it) {
        Registry<Entity>::entry e = *it;
        if (strcmp(e.getName(), name) == 0) {
            return (e.instantiate());
        }
    }
    return NULL;
}
