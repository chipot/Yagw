#include "SimpleFollowingBehavior.h"
#include "EntityFactory.h"

SimpleFollowingBehavior::SimpleFollowingBehavior() : EnnemyBehavior() {
    rotationSpeed = 0;
    moveSpeed = 1;
    direction = QPointF(0,0);
    growingUp = true;
    ent = NULL;
    actualSize = 1.0;
    maxSize = 1.5;
    growingTimeLength = 2000;
    startGrowingUpTimer();
}

void SimpleFollowingBehavior::behave(Entity *entity) {
    ent = entity;
    if (entity->playerMoved()) {
        updateDirection(entity->pos(), entity->getPlayerPosition());
    }
    QPointF move = direction*moveSpeed;
    entity->setMove(move);
    entity->setRotation(rotationSpeed);
    growUp();
}
