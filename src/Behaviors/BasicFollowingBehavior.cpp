#include "Registry.h"

#include "Behaviors/BasicFollowingBehavior.h"
#include "Calculator.h"

void BasicFollowingBehavior::move()
{
    if (entity) {
        QVector2D direction = Calculator::calcDirectionVector(entity->pos(), target->pos());
        entity->setMove(Calculator::calcMovement(direction.toPointF(), entity->getSpeed(), time.elapsed()));
        time.restart();
    }

}


void BasicFollowingBehavior::init() {
    qDebug() << "following move init";
    if (entity)
        entity->setSpeed(100);
}

BasicFollowingBehavior *BasicFollowingBehavior::copy() const {
    return new BasicFollowingBehavior(0, target);
}

Registry<MoveBehavior>::Add<BasicFollowingBehavior> BasicFollowingBehavior("BasicFollowingBehavior", "1: une meilleur expliquation est bienvenue");
