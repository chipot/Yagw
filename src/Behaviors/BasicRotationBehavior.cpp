#include "Behaviors/BasicRotationBehavior.h"

void BasicRotationBehavior::rotate() {
    if (entity) {
        entity->setRotation(rotationSpeed);
    }
}

BasicRotationBehavior *BasicRotationBehavior::copy() {
    return new BasicRotationBehavior(0, rotationSpeed);
}
