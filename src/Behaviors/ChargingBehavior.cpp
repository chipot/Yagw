#include "Behaviors/ChargingBehavior.h"
#include "Calculator.h"

void ChargingBehavior::move() {
    if (entity) {
            QVector2D orientation = Calculator::calcDirectionVector(entity->pos(), direction);
            QPointF move = Calculator::calcMovement(orientation.toPointF(), entity->getSpeed(), time.elapsed());
            entity->setMove(move);
            time.restart();
    }
}

void ChargingBehavior::updateDirection() {
    direction = target->pos();
}

void ChargingBehavior::init() {
    BasicFollowingBehavior::init();
    direction = target->pos();
    directionUpdatingTimer.connect(&directionUpdatingTimer, SIGNAL(timeout()), this, SLOT(updateDirection()));
    directionUpdatingTimer.start(4000);
}

ChargingBehavior *ChargingBehavior::copy() {
    return new ChargingBehavior(0, target, speed);
}
