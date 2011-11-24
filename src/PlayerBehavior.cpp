#include "PlayerBehavior.h"
#include "EntityFactory.h"
#include "SoundCenter.h"

uint qHash(QPointF const &ptr) {
    return (ptr.x() * 1000 + ptr.y());
}

PlayerBehavior::PlayerBehavior() {
    qDebug() << "instance playerBehavior";

    rotationSpeed = 7;
    moveSpeed = 2;
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
    Entity *fire = EntityFactory::getEntity("shuriken");
    fireBehavior->setDirection(direction);
    fire->setBehavior(fireBehavior);
    return fire;
}

void PlayerBehavior::fireLvl1() {
    Entity *fire = createFire(fireDirection);
    this->entityTemp->scene()->addItem(fire);
    fire->moveBy(entityTemp->pos().x(), entityTemp->pos().y());

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
        fireDirection = QPointF(0, 0);
        SoundCenter::get_instance()->play("quack");
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
            case Qt::Key_Down :
                fireDirection.setY(0);
                break;
            case Qt::Key_Right :
            case Qt::Key_Left :
                fireDirection.setX(0);
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
    case Qt::Key_Up :
        fireDirection.setY(-1);
        break;
    case Qt::Key_Left :
        fireDirection.setX(-1);
        break;
    case Qt::Key_Down :
        fireDirection.setY(1);
        break;
    case Qt::Key_Right :
        fireDirection.setX(1);
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
    return rotate;
}

void PlayerBehavior::behave(Entity *entity) {
    this->entityTemp = entity;
    QPointF _move = move;
    if (_move.x() != 0 && _move.y() != 0) {
        _move.setX(_move.x() / 2);
        _move.setY(_move.y() / 2);
    }
    _move *= moveSpeed;
    entity->setMove(_move);
    this->fire();
    entity->setRotation(this->calcRotation());
}
