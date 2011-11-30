#include "Registry.h"
#include "Behaviors/SimpleMoveBehavior.h"

SimpleMoveBehavior::SimpleMoveBehavior(QPointF dir, int s) :
    direction(dir), speed(s)
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

void SimpleMoveBehavior::init() {
    if (entity)
        entity->setSpeed(speed);
}

Registry<MoveBehavior>::Add<SimpleMoveBehavior> SimpleMoveBehavior("SimpleMoveBehavior", "0: une meilleur expliquation est bienvenue");
