#include "Registry.h"
#include "Behaviors/ImplodingBehavior.h"

void ImplodingBehavior::start() {
}

void ImplodingBehavior::transform() {
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

void ImplodingBehavior::changeSize() {
    growingUp = !growingUp;
}

ImplodingBehavior *ImplodingBehavior::copy() const {
    return new ImplodingBehavior(growingDuration, maxSize);
}

Registry<TransformationBehavior>::Add<ImplodingBehavior> ImplodingBehavior("ImplodingBehavior", "5: une meilleur expliquation est bienvenue");
