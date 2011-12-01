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

GrowingBehavior *GrowingBehavior::copy() const {
    return new GrowingBehavior(growingDuration, maxSize);
}
