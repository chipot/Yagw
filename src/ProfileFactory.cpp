#include "ProfileFactory.h"

MoveBehaviorFactory MoveBehaviorFactor;

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

MoveBehavior *MoveBehaviorFactory::getRandom() {
    Registry<MoveBehavior>::iterator it = Registry<MoveBehavior>::begin();
    Registry<MoveBehavior>::iterator ite = Registry<MoveBehavior>::end();
    int val = qrand();
    int count = 0;

    for (;it != ite; ++it) {
      count++;
    }

    val %= count;
    count = 0;
    it = Registry<MoveBehavior>::begin();
    ite = Registry<MoveBehavior>::end();

    for (;it != ite; ++it, ++count) {
      if (count == val)
      {
        Registry<MoveBehavior>::entry e = *it;
        return e.instantiate();
      }
    }
    return NULL;
}

ShootBehaviorFactory ShootBehaviorFactory;

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

ShootBehavior *ShootBehaviorFactory::getRandom() {
    Registry<ShootBehavior>::iterator it = Registry<ShootBehavior>::begin();
    Registry<ShootBehavior>::iterator ite = Registry<ShootBehavior>::end();
    int val = qrand();
    int count = 0;

    for (;it != ite; ++it) {
      count++;
    }

    val %= count;
    count = 0;
    it = Registry<ShootBehavior>::begin();
    ite = Registry<ShootBehavior>::end();

    for (;it != ite; ++it, ++count) {
      if (count == val)
      {
        Registry<ShootBehavior>::entry e = *it;
        return e.instantiate();
      }
    }
    return NULL;
}

TransformationBehaviorFactory TransformationBehaviorFactory;

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

TransformationBehavior *TransformationBehaviorFactory::getRandom() {
    Registry<TransformationBehavior>::iterator it = Registry<TransformationBehavior>::begin();
    Registry<TransformationBehavior>::iterator ite = Registry<TransformationBehavior>::end();
    int val = qrand();
    int count = 0;

    for (;it != ite; ++it) {
      count++;
    }

    val %= count;
    count = 0;
    it = Registry<TransformationBehavior>::begin();
    ite = Registry<TransformationBehavior>::end();

    for (;it != ite; ++it, ++count) {
      if (count == val)
      {
        Registry<TransformationBehavior>::entry e = *it;
        return e.instantiate();
      }
    }
    return NULL;
}


RotationBehaviorFactory RotationBehaviorFactory;

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

RotationBehavior *RotationBehaviorFactory::getRandom() {
    Registry<RotationBehavior>::iterator it = Registry<RotationBehavior>::begin();
    Registry<RotationBehavior>::iterator ite = Registry<RotationBehavior>::end();
    int val = qrand();
    int count = 0;

    for (;it != ite; ++it) {
      count++;
    }

    val %= count;
    count = 0;
    it = Registry<RotationBehavior>::begin();
    ite = Registry<RotationBehavior>::end();

    for (;it != ite; ++it, ++count) {
      if (count == val)
      {
        Registry<RotationBehavior>::entry e = *it;
        return e.instantiate();
      }
    }
    return NULL;
}
