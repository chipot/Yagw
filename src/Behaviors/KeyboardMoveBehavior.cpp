#include "Behaviors/KeyboardMoveBehavior.h"

KeyboardMoveBehavior::KeyboardMoveBehavior() : displacement(QPointF(0,0)), time(QTime())
{
    time.start();
}

void KeyboardMoveBehavior::move() {
    if (entity && (displacement.x() != 0 || displacement.y() != 0))
        entity->setMove(calcMove(displacement, entity->getSpeed()));
}

void KeyboardMoveBehavior::keyPressEvent( QKeyEvent * event ) {
    switch (event->key()) {
        case Qt::Key_W :
            displacement.setY(-1);
            break;
        case Qt::Key_A :
            displacement.setX(-1);
            break;
        case Qt::Key_S :
            displacement.setY(1);
            break;
        case Qt::Key_D :
            displacement.setX(1);
            break;
        default :
            break;
    }
}

void KeyboardMoveBehavior::keyReleaseEvent( QKeyEvent * event ) {
    switch (event->key()) {
        case Qt::Key_W :
            if (displacement.y() == -1)
                displacement.setY(0);
            break;
        case Qt::Key_S :
            if (displacement.y() == 1)
                displacement.setY(0);
            break;
        case Qt::Key_A :
            if (displacement.x() == -1)
                displacement.setX(0);
            break;
        case Qt::Key_D :
            if (displacement.x() == 1)
                displacement.setX(0);
                break;
        default :
            break;
    }
}
