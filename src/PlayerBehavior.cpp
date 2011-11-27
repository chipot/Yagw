#include <algorithm>
#include "PlayerBehavior.h"
#include "EntityFactory.h"



uint qHash(QPointF const &ptr) {
    return (ptr.x() * 1000 + ptr.y());
}

PlayerBehavior::PlayerBehavior() {
    qDebug() << "instance playerBehavior";

    rotationSpeed = 7;
    moveSpeed = 3;
    directions[QPointF(0, 0)] = 0;
    directions[QPointF(1, -1)] = 45;
    directions[QPointF(1, 0)] = 90;
    directions[QPointF(1, 1)] = 135;
    directions[QPointF(0, 1)] = 180;
    directions[QPointF(-1, 1)] = 225;
    directions[QPointF(-1, 0)] = 270;
    directions[QPointF(-1, -1)] = 315;
    directions[QPointF(0, -1)] = 360;
    fireDirection = QPointF(0, 0);
    move = QPointF(0, 0);
    fireLevel = 1;
    fl << &PlayerBehavior::fireLvl1;
    fl << &PlayerBehavior::fireLvl2;
    fl << &PlayerBehavior::fireLvl3;
    angle = 90;
}

Entity *PlayerBehavior::createFire(QPointF direction) {
    FireBehavior *fireBehavior = new FireBehavior();
    fireBehavior->setDirection(direction);

    Entity *fire = EntityFactory::getEntity("shuriken");
    fire->setScene(entityTemp->getScene());
    fire->setBehavior(fireBehavior);
    emit entityTemp->getScene()->newEntity(fire);
    return fire;
}

void PlayerBehavior::fireLvl1() {
    Entity *fire = createFire(fireDirection);
    this->entityTemp->scene()->addItem(fire);
    qreal s = std::max(this->entityTemp->boundingRect().height(), this->entityTemp->boundingRect().width()) *1.2;
    fire->moveBy(entityTemp->pos().x() + fireDirection.x() * s, entityTemp->pos().y() + fireDirection.y() * s);
}

void PlayerBehavior::fireLvl2() {
    fireLvl1();
}

void PlayerBehavior::fireLvl3() {
    fireLvl1();
}

void PlayerBehavior::fire() {
    if (fireDirection.x() != 0 || fireDirection.y() != 0) {
        (this->*fl[fireLevel-1])();
    }
}

void PlayerBehavior::keyPressEvent( QKeyEvent * event ) {
    switch (event->key()) {
        case Qt::Key_W :
            move.setY(-1);
            break;
        case Qt::Key_A :
            move.setX(-1);
            break;
        case Qt::Key_S :
            move.setY(1);
            break;
        case Qt::Key_D :
            move.setX(1);
            break;
        case Qt::Key_Up :
            fireDirection.setY(-1);
            break;
        case Qt::Key_Down :
            fireDirection.setY(1);
            break;
        case Qt::Key_Right :
            fireDirection.setX(1);
            break;
        case Qt::Key_Left :
            fireDirection.setX(-1);
            break;
        default :
            break;
    }
}

void PlayerBehavior::keyReleaseEvent( QKeyEvent * event ) {
    switch (event->key()) {
        case Qt::Key_W :
            if (move.y() == -1)
                move.setY(0);
            break;
        case Qt::Key_S :
            if (move.y() == 1)
                move.setY(0);
            break;
        case Qt::Key_A :
            if (move.x() == -1)
                move.setX(0);
            break;
        case Qt::Key_D :
            if (move.x() == 1)
                move.setX(0);
                break;
        case Qt::Key_Down :
        if (fireDirection.y() == 1)
            fireDirection.setY(0);
            break;
        case Qt::Key_Up :
        if (fireDirection.y() == -1)
            fireDirection.setY(0);
            break;
        case Qt::Key_Left :
        if (fireDirection.x() == -1)
            fireDirection.setX(0);
            break;
        case Qt::Key_Right :
        if (fireDirection.x() == 1)
            fireDirection.setX(0);
            break;
        default :
            break;
    }
}

int PlayerBehavior::calcRotation() {
    int direction = directions[QPointF(move)];
    if (direction == 0) {
        return 0;
    }
    int rotate = - rotationSpeed;
    if ((direction - angle <= 180 && direction - angle > 0) || direction - angle <= -180)
        rotate = rotationSpeed;
    if (direction == angle)
        rotate = 0;
    angle += rotate;

    if (angle >= 360) {
        angle -= 360;
    }
    if (angle <= 0) {
        angle+= 360;
    }
    // retourne l'écart (signé) avec le multiple de 45 le plus proche
    int gap = abs((angle - (angle / 45 * 45))) < abs(angle - (angle / 45 * 45 + 45)) ? -1*(angle - (angle / 45 * 45)) : (((angle / 45 * 45)+45) - angle);
    if (abs(gap) < rotationSpeed) {
        rotate += gap;
        angle += gap;
    }
    return rotate;
}

void PlayerBehavior::behave(Entity *entity) {
    this->entityTemp = entity;
    this->fire();
    QPointF _move = move;
/*
    if (_move.x() != 0 && _move.y() != 0) {
        _move.setX(_move.x() / 2);
        _move.setY(_move.y() / 2);
    }
*/
    _move *= moveSpeed;
    entity->setMove(_move);
    if (_move.x() != 0 || _move.y() != 0) {
        emit playerMoved();
    }
    entity->setRotation(this->calcRotation());
}
