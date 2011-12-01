#include "Registry.h"

#include "Behaviors/BasicFollowingBehavior.h"
#include "Calculator.h"

void BasicFollowingBehavior::move()
{
    if (entity) {
        QVector2D direction = Calculator::calcDirectionVector(entity->pos(), target->pos());
        entity->setMove(calcMove(direction.toPointF(), entity->getSpeed()));
    }

}


void BasicFollowingBehavior::init() {
    qDebug() << "following move init";
    if (entity)
        entity->setSpeed(100);
}


Registry<MoveBehavior>::Add<BasicFollowingBehavior> BasicFollowingBehavior("BasicFollowingBehavior", "1: une meilleur expliquation est bienvenue");
