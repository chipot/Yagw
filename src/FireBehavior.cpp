#include "FireBehavior.h"

FireBehavior::FireBehavior() {
    rotationSpeed = 6;
    direction = QPointF(0,0);
}

void FireBehavior::behave(Entity *entity) {
    entity->setMove(direction);
    entity->setRotation(rotationSpeed);
}

void FireBehavior::setDirection(QPointF &dir) {
    direction = dir;
}
