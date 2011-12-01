#include "Registry.h"

#include "Behaviors/SimpleRotationBehavior.h"
#include "Behaviors/BasicFollowingBehavior.h"
#include "Calculator.h"

void SimpleRotationBehavior::rotate()
{
    if (entity) {
        entity->setRotation(entity->getRotationSpeed());
    }
}

void SimpleRotationBehavior::init() {
    if (entity) {
        entity->setRotationSpeed(20);
    }
}

SimpleRotationBehavior *SimpleRotationBehavior::copy() const {
    return new SimpleRotationBehavior(0, target, angle);
}

Registry<RotationBehavior>::Add<SimpleRotationBehavior> SimpleRotationBehavior("SimpleRotationBehavior", "1: une meilleur expliquation est bienvenue");
