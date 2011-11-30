#include "ProfileFactory.h"
#include "Behaviors.h"

MoveBehaviorFactory moveBehaviorFactory;

MoveBehavior *MoveBehaviorFactory::getMoveBehavior(const char *name) {
    Registry<MoveBehavior>::iterator it = Registry<MoveBehavior>::begin();
    Registry<MoveBehavior>::iterator ite = Registry<MoveBehavior>::end();
    for (;it != ite; ++it) {
        Registry<MoveBehavior>::entry e = *it;
        if (strcmp(e.getName(), name) == 0) {
            return (e.instantiate());
        }
    }
    return NULL;
}

MoveBehavior *MoveBehaviorFactory::getRandom(int level, Entity *player) {
    Registry<MoveBehavior>::iterator it = Registry<MoveBehavior>::begin();
    Registry<MoveBehavior>::iterator ite = Registry<MoveBehavior>::end();
    int val = qrand();
    int count = 0;

    for (;it != ite; ++it)
      {
        Registry<MoveBehavior>::entry e = *it;
        if (e.getDesc() && e.getDesc()[0] - '0' <= level)
          ++count;
      }
    if (!count)
      return (NULL);
    val = val % count + 1;
    count = 0;
    it = Registry<MoveBehavior>::begin();
    ite = Registry<MoveBehavior>::end();

    for (;it != ite; ++it) {
      Registry<MoveBehavior>::entry e = *it;
      if (e.getDesc() && e.getDesc()[0] - '0' <= level)
        ++count;
      if (count == val)
        {
          MoveBehavior *be = e.instantiate();
          be->setTarget(player);
          return be;
        }
    }
    return NULL;
}

ShootBehaviorFactory shootBehaviorFactory;

ShootBehavior *ShootBehaviorFactory::getShootBehavior(const char *name) {
  Registry<ShootBehavior>::iterator it = Registry<ShootBehavior>::begin();
    Registry<ShootBehavior>::iterator ite = Registry<ShootBehavior>::end();
    for (;it != ite; ++it) {
      Registry<ShootBehavior>::entry e = *it;
      if (strcmp(e.getName(), name) == 0) {
            return (e.instantiate());
      }
    }
    return NULL;
}

ShootBehavior *ShootBehaviorFactory::getRandom(int level) {
    Registry<ShootBehavior>::iterator it = Registry<ShootBehavior>::begin();
    Registry<ShootBehavior>::iterator ite = Registry<ShootBehavior>::end();
    int val = qrand();
    int count = 0;

    for (;it != ite; ++it)
      {
        Registry<ShootBehavior>::entry e = *it;
        if (e.getDesc() && e.getDesc()[0] - '0' <= level)
          ++count;
      }
    if (!count)
      return (NULL);
    val = val % count + 1;
    count = 0;
    it = Registry<ShootBehavior>::begin();
    ite = Registry<ShootBehavior>::end();

    for (;it != ite; ++it) {
      Registry<ShootBehavior>::entry e = *it;
      if (e.getDesc() && e.getDesc()[0] - '0' <= level)
        ++count;
      if (count == val)
        return e.instantiate();
    }
    return NULL;
}

TransformationBehaviorFactory transformationBehaviorFactory;

TransformationBehavior *TransformationBehaviorFactory::getTransformationBehavior(const char *name) {
    Registry<TransformationBehavior>::iterator it = Registry<TransformationBehavior>::begin();
    Registry<TransformationBehavior>::iterator ite = Registry<TransformationBehavior>::end();
    for (;it != ite; ++it) {
        Registry<TransformationBehavior>::entry e = *it;
        if (strcmp(e.getName(), name) == 0) {
            return (e.instantiate());
        }
    }
    return NULL;
}

TransformationBehavior *TransformationBehaviorFactory::getRandom(int level) {
    Registry<TransformationBehavior>::iterator it = Registry<TransformationBehavior>::begin();
    Registry<TransformationBehavior>::iterator ite = Registry<TransformationBehavior>::end();
    int val = qrand();
    int count = 0;


    for (;it != ite; ++it)
      {
        Registry<TransformationBehavior>::entry e = *it;
        if (e.getDesc() && e.getDesc()[0] - '0' <= level)
          ++count;
      }
    if (!count)
      return (NULL);
    val = val % count + 1;
    count = 0;
    it = Registry<TransformationBehavior>::begin();
    ite = Registry<TransformationBehavior>::end();
    for (;it != ite; ++it) {
      Registry<TransformationBehavior>::entry e = *it;
      if (e.getDesc() && e.getDesc()[0] - '0' <= level)
        ++count;
      if (count == val)
        return e.instantiate();
    }
    return NULL;
}


RotationBehaviorFactory rotationBehaviorFactory;

RotationBehavior *RotationBehaviorFactory::getRotationBehavior(const char *name) {
    Registry<RotationBehavior>::iterator it = Registry<RotationBehavior>::begin();
    Registry<RotationBehavior>::iterator ite = Registry<RotationBehavior>::end();
    for (;it != ite; ++it) {
        Registry<RotationBehavior>::entry e = *it;
        if (strcmp(e.getName(), name) == 0) {
            return (e.instantiate());
        }
    }
    return NULL;
}

RotationBehavior *RotationBehaviorFactory::getRandom(int level, Entity *player) {
    Registry<RotationBehavior>::iterator it = Registry<RotationBehavior>::begin();
    Registry<RotationBehavior>::iterator ite = Registry<RotationBehavior>::end();
    int val = qrand();
    int count = 0;

    for (;it != ite; ++it)
      {
        Registry<RotationBehavior>::entry e = *it;
        if (e.getDesc() && e.getDesc()[0] - '0' <= level)
          ++count;
      }
    if (!count)
      return (NULL);
    val = val % count + 1;
    count = 0;
    it = Registry<RotationBehavior>::begin();
    ite = Registry<RotationBehavior>::end();

    for (;it != ite; ++it) {
      Registry<RotationBehavior>::entry e = *it;
      if (e.getDesc() && e.getDesc()[0] - '0' <= level)
        ++count;
      if (count == val)
        {
          RotationBehavior *re = e.instantiate();
          re->setTarget(player);
          return re;
        }
    }
    return NULL;
}
