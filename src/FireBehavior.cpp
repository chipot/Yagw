#include "Registry.h"
#include "FireBehavior.h"

FireBehavior::FireBehavior() {
    rotationSpeed = 18;
    moveSpeed = 8;
    direction = QPointF(0,0);
}

void FireBehavior::behave(Entity *entity) {
    QPointF move = direction*moveSpeed;
    entity->setMove(move);
    entity->setRotation(rotationSpeed);
}

void FireBehavior::setDirection(QPointF dir) {
    direction = dir;
}

void FireBehavior::setRotationSpeed(int speed) {
    rotationSpeed = speed;
}

