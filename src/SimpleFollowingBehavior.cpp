#include "SimpleFollowingBehavior.h"
#include "EntityFactory.h"

SimpleFollowingBehavior::SimpleFollowingBehavior() {
    rotationSpeed = 0;
    moveSpeed = 1;
    direction = QPointF(0,0);
    growingUp = true;
    ent = NULL;
    actualSize = 1.0;
    maxSize = 1.5;
    growingTimeLength = 2000;
    QTimer *changeSizeTime = new QTimer();
    changeSizeTime->connect(changeSizeTime, SIGNAL(timeout()), this, SLOT(changeSize()));
    changeSizeTime->start(growingTimeLength);
}


void SimpleFollowingBehavior::updateDirection(QPointF entityPos, QPointF playerPos) {
    QPointF vector(playerPos.x() - entityPos.x(), playerPos.y() - entityPos.y());
    QVector2D dir(vector);
    dir.normalize();
    direction = QPointF(dir.x(), dir.y());
}

void SimpleFollowingBehavior::growUp() {
    float scale = ((maxSize-1.0)/(growingTimeLength/60));
    if (growingUp == true) {
        ent->setScale(actualSize+scale);
        actualSize+=scale;
    } else {
        ent->setScale(actualSize-scale);
        actualSize -= scale;
    }
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

void SimpleFollowingBehavior::setDirection(QPointF dir) {
    direction = dir;
}

void SimpleFollowingBehavior::setRotationSpeed(int speed) {
    rotationSpeed = speed;
}

void SimpleFollowingBehavior::changeSize() {
    growingUp = !growingUp;
}
