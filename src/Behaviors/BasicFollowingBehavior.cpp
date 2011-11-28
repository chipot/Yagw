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
                                           entityToFollow->pos()),
                             entity->getSpeed()));
    }

}
