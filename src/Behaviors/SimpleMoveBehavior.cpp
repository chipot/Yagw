#include "Registry.h"
#include "Behaviors/SimpleMoveBehavior.h"
#include "Calculator.h"

SimpleMoveBehavior::SimpleMoveBehavior(QPointF dir, int s) :
    direction(dir), speed(s)
{

}

void SimpleMoveBehavior::move()
{
    if (entity) {
        entity->setMove(Calculator::calcMovement(direction, entity->getSpeed(), time.elapsed()));
        time.restart();
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

SimpleMoveBehavior *SimpleMoveBehavior::copy() const {
    return new SimpleMoveBehavior(direction, speed);
}

Registry<MoveBehavior>::Add<SimpleMoveBehavior> SimpleMoveBehavior("SimpleMoveBehavior", "0: une meilleur expliquation est bienvenue");
