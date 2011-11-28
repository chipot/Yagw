#include <algorithm>
#include "Behaviors/KeyboardFireBehavior.h"
#include "EntityFactory.h"
#include <QtGlobal>
#include "Profile.h"
#include "Behaviors/SimpleMoveBehavior.h"
#include "YagwScene.h"

KeyboardFireBehavior::KeyboardFireBehavior() : fireDirection(QPointF(0,0)), time(QTime()), fireFrequency(1000/6)
{
    time.start();
}

Entity *KeyboardFireBehavior::createFire(QPointF direction) {
    Entity *fire = EntityFactory::getEntity("fire01");
    SimpleMoveBehavior *moveBehavior = new SimpleMoveBehavior(direction);
    Profile *profile = new Profile(moveBehavior);

    fire->setProfile(profile);
    fire->setScene(entity->getScene());
    emit this->fireLaunched(fire);
//    emit entity->getScene()->newFire(fire);
    return fire;
}


void KeyboardFireBehavior::fire() {
    if (fireDirection.x() != 0 || fireDirection.y() != 0) {
        if (time.elapsed() > fireFrequency) {
            using namespace std;
            Entity *fire = createFire(fireDirection);
            this->entity->scene()->addItem(fire);
            QRectF brect = this->entity->boundingRect();
            qreal s = max(brect.height(), brect.width());
            s *= 1.4;
            fire->moveBy(entity->pos().x() + fireDirection.x() * s, entity->pos().y() + fireDirection.y() * s);
            time.restart();
        }
    }
}

void KeyboardFireBehavior::setFireFrequency(int frequency) {
    fireFrequency = frequency;
}

void KeyboardFireBehavior::keyPressEvent( QKeyEvent * event ) {
    switch (event->key()) {
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

void KeyboardFireBehavior::keyReleaseEvent( QKeyEvent * event ) {
    switch (event->key()) {
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


