#include "EntityFactory.h"

EntityFactory Factory;

Entity *EntityFactory::getEntity(const char *name) {
    Registry<Entity>::iterator it = Registry<Entity>::begin();
    Registry<Entity>::iterator ite = Registry<Entity>::end();
    for (;it != ite; ++it) {
        Registry<Entity>::entry e = *it;
        if (strcmp(e.getName(), name) == 0) {
            Entity *ent = e.instantiate();
            ent->setIndex(e.getName());
            return ent;
        }
    }
    return NULL;
}

Entity *EntityFactory::getRandom(int level) {
    Registry<Entity>::iterator it = Registry<Entity>::begin();
    Registry<Entity>::iterator ite = Registry<Entity>::end();
    int val = qrand();
    int count = 0;

    for (;it != ite; ++it)
      {
        Registry<Entity>::entry e = *it;
        if (e.getDesc() && e.getDesc()[0] - '0' <= level)
          ++count;
      }
    if (!count)
      return (NULL);
    val = val % count + 1;
    count = 0;
    it = Registry<Entity>::begin();
    ite = Registry<Entity>::end();

    for (;it != ite; ++it)
    {
      Registry<Entity>::entry e = *it;
      if (e.getDesc() && e.getDesc()[0] - '0' <= level)
        ++count;
      if (count == val) {
          Entity *ent = e.instantiate();
          ent->setIndex(e.getName());
          return ent;
      }
    }
    return NULL;
}
