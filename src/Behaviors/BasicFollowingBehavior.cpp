#include "Behaviors/BasicFollowingBehavior.h"

QPointF BasicFollowingBehavior::calcDirection(QPointF firstPoint, QPointF secondPoint)
{
    QPointF vector(secondPoint.x() - firstPoint.x(), secondPoint.y() - firstPoint.y());
    QVector2D dir(vector);
    dir.normalize();
    return (QPointF(dir.x(), dir.y()));
}

void BasicFollowingBehavior::move()
{
    if (entity) {
        entity->setMove(
                    calcMove(calcDirection(entity->pos(),
                                           target->pos()),
                             entity->getSpeed()));
    }

}

void BasicFollowingBehavior::setTarget(Entity *entity) {
    target = entity;
}

void BasicFollowingBehavior::init() {
    if (entity)
        entity->setRotationSpeed(0);
}
