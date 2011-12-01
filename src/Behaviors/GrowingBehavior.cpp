#include "Behaviors/GrowingBehavior.h"

void GrowingBehavior::start() {
    timer.connect(&timer, SIGNAL(timeout()), this, SLOT(changeSize()));
    timer.start(growingDuration);
}

void GrowingBehavior::transform() {
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
