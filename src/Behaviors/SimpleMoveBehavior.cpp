#include "Behaviors/SimpleMoveBehavior.h"

SimpleMoveBehavior::SimpleMoveBehavior(QPointF dir) :
    direction(dir)
{

}

void SimpleMoveBehavior::move()
{
    if (entity) {
        entity->setMove(calcMove(direction, entity->getSpeed()));
    }
}

void SimpleMoveBehavior::setDirection(QPointF dir)
{
    direction = dir;
}
