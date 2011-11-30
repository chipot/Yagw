#include "Registry.h"
#include "Behaviors/KeyboardMoveBehavior.h"
#include "YagwScene.h"


KeyboardMoveBehavior::KeyboardMoveBehavior() : displacement(QPointF(0,0)), maxSpeed(200), time(QTime())
{
    time.start();

}

KeyboardMoveBehavior::~KeyboardMoveBehavior() {
    if (entity)
        entity->getScene()->disconnect(this);
}

void KeyboardMoveBehavior::move() {
    if (entity) {
        int speed = entity->getSpeed();
        if (speed-3 >= 0 && displacement == QPointF(0, 0))
            entity->setSpeed(speed-3);
        if (speed+3 <= maxSpeed && displacement != QPointF(0, 0))
            entity->setSpeed(speed+3);
        QPointF move = calcMove((displacement != QPointF(0, 0) ? displacement : entity->getMove()), entity->getSpeed());
        entity->setMove(move);
    }
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

void KeyboardMoveBehavior::init() {
    if (entity)
        entity->setSpeed(maxSpeed);
}
Registry<MoveBehavior>::Add<KeyboardMoveBehavior> KeyboardMoveBehavior("SimpleMoveBehavior", "une meilleur expliquation est bienvenue");
