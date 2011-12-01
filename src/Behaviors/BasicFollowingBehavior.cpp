#include "Registry.h"

#include "Behaviors/BasicFollowingBehavior.h"
#include "Calculator.h"

void BasicFollowingBehavior::move()
{
    if (entity) {
        QVector2D direction = Calculator::calcDirectionVector(entity->pos(),
                                                              target->pos());
        QPointF move = Calculator::calcMovement(direction.toPointF(),
                                                entity->getSpeed(),
                                                time.elapsed());
        entity->setMove(move);
        time.restart();
    }

}


void BasicFollowingBehavior::init() {
    if (entity)
        entity->setSpeed(speed);
}

BasicFollowingBehavior *BasicFollowingBehavior::copy() {
    return new BasicFollowingBehavior(0, target, speed);
}

Registry<MoveBehavior>::Add<BasicFollowingBehavior> BasicFollowingBehavior("BasicFollowingBehavior", "1: une meilleur expliquation est bienvenue");
