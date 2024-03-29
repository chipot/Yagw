#include "Registry.h"
#include "Behaviors/GrowingBehavior.h"

void GrowingBehavior::start() {
}

void GrowingBehavior::transform() {
    if (!timer.isActive()) {
        timer.start(growingDuration);
    }
    if (entity) {
        if (growingUp == true) {
            entity->setScale(actualSize+scale);
            actualSize+=scale;
        } else {
            entity->setScale(actualSize-scale);
            actualSize -= scale;
        }
    }
}

void GrowingBehavior::changeSize() {
    growingUp = !growingUp;
}

GrowingBehavior *GrowingBehavior::copy() {
    return new GrowingBehavior(growingDuration, maxSize);
}

Registry<TransformationBehavior>::Add<GrowingBehavior> GrowingBehavior("GrowingBehavior", "5: une meilleur expliquation est bienvenue");
