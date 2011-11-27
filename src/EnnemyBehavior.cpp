#include "EnnemyBehavior.h"
#include "EntityFactory.h"

EnnemyBehavior::EnnemyBehavior() {
    rotationSpeed = 0;
    moveSpeed = 1;
    direction = QPointF(0,0);
    growingUp = true;
    ent = NULL;
    actualSize = 1.0;
    maxSize = 1.0;
    growingTimeLength = 100000;
}

void EnnemyBehavior::startGrowingUpTimer() {
    QTimer *changeSizeTime = new QTimer();
    changeSizeTime->connect(changeSizeTime, SIGNAL(timeout()), this, SLOT(changeSize()));
    changeSizeTime->start(growingTimeLength);
}

void EnnemyBehavior::updateDirection(QPointF entityPos, QPointF playerPos) {
    QPointF vector(playerPos.x() - entityPos.x(), playerPos.y() - entityPos.y());
    QVector2D dir(vector);
    dir.normalize();
    direction = QPointF(dir.x(), dir.y());
}

void EnnemyBehavior::growUp() {
    float scale = ((maxSize-1.0)/(growingTimeLength/60));
    if (growingUp == true) {
        ent->setScale(actualSize+scale);
        actualSize+=scale;
    } else {
        ent->setScale(actualSize-scale);
        actualSize -= scale;
    }
}

void EnnemyBehavior::behave(Entity *entity) {
}

void EnnemyBehavior::setDirection(QPointF dir) {
    direction = dir;
}

void EnnemyBehavior::setRotationSpeed(int speed) {
    rotationSpeed = speed;
}

void EnnemyBehavior::changeSize() {
    growingUp = !growingUp;
}

QPointF EnnemyBehavior::playerPos() {
    if (ent) {
        QGraphicsScene *scene = ent->scene();
        QGraphicsItem *player = scene->focusItem();
        if (player) {
            QPointF pos = player->pos();
            return (pos);
        }
    }
    return QPointF(0, 0);
}
