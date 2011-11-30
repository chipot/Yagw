#include "Registry.h"
#include "Behaviors/KeyboardRotationBehavior.h"
#include "YagwScene.h"


/*
uint qHash(QPointF const &ptr) {
    return (ptr.x() * 1000 + ptr.y());
}
*/

KeyboardRotationBehavior::KeyboardRotationBehavior() :
    angle(90), orientation(QPointF(0,0))
{
    directions[QPointF(0, 0)] = 0;
    directions[QPointF(1, -1)] = 45;
    directions[QPointF(1, 0)] = 90;
    directions[QPointF(1, 1)] = 135;
    directions[QPointF(0, 1)] = 180;
    directions[QPointF(-1, 1)] = 225;
    directions[QPointF(-1, 0)] = 270;
    directions[QPointF(-1, -1)] = 315;
    directions[QPointF(0, -1)] = 360;
}

KeyboardRotationBehavior::~KeyboardRotationBehavior() {
    if (entity) {
        entity->getScene()->disconnect(this);
    }
}

int KeyboardRotationBehavior::calcRotation() {
    int direction = directions[orientation];
    if (direction == 0) {
        return 0;
    }
    int rotate = - entity->getRotationSpeed();
    if ((direction - angle <= 180 && direction - angle > 0) || direction - angle <= -180)
        rotate = entity->getRotationSpeed();
    if (direction == angle)
        rotate = 0;
    angle += rotate;

    if (angle > 360) {
        angle -= 360;
    }
    if (angle <= 0) {
        angle += 360;
    }

    // retourne l'écart (signé) avec le multiple de 45 le plus proche
    int gap = abs((angle - (angle / 45 * 45))) < abs(angle - (angle / 45 * 45 + 45)) ? -1*(angle - (angle / 45 * 45)) : (((angle / 45 * 45)+45) - angle);
    if (abs(gap) < entity->getRotationSpeed()) {
        rotate += gap;
        angle += gap;
    }
    return rotate;
}

void KeyboardRotationBehavior::rotate() {
        if (entity) {
        entity->setRotation(this->calcRotation());
        }
}

void KeyboardRotationBehavior::keyPressEvent( QKeyEvent * event ) {
    switch (event->key()) {
        case Qt::Key_W :
            orientation.setY(-1);
            break;
        case Qt::Key_A :
            orientation.setX(-1);
            break;
        case Qt::Key_S :
            orientation.setY(1);
            break;
        case Qt::Key_D :
            orientation.setX(1);
            break;
        default :
            break;
    }
}

void KeyboardRotationBehavior::keyReleaseEvent( QKeyEvent * event ) {
    switch (event->key()) {
        case Qt::Key_W :
            if (orientation.y() == -1)
                orientation.setY(0);
            break;
        case Qt::Key_S :
            if (orientation.y() == 1)
                orientation.setY(0);
            break;
        case Qt::Key_A :
            if (orientation.x() == -1)
                orientation.setX(0);
            break;
        case Qt::Key_D :
            if (orientation.x() == 1)
                orientation.setX(0);
                break;
        default :
            break;
    }
}

void KeyboardRotationBehavior::init() {
    if (!entity)
        return;
    entity->setRotationSpeed(7);
}

Registry<RotationBehavior>::Add<KeyboardRotationBehavior> KeyboardRotationBehavior("KeyboardRotationBehavior", "une meilleur expliquation est bienvenue");
