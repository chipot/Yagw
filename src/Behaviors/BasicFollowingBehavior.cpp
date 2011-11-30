#include "Registry.h"

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
    qDebug() << entity->getMove();
    if (entity) {
        entity->setMove(
                    calcMove(BasicFollowingBehavior::calcDirection(entity->pos(),
                                           target->pos()),
                             entity->getSpeed()));
    }

}

void BasicFollowingBehavior::setTarget(Entity *entity) {
    target = entity;
}

void BasicFollowingBehavior::init() {
    qDebug() << "following move init";
    if (entity)
        entity->setSpeed(100);
}


Registry<MoveBehavior>::Add<BasicFollowingBehavior> BasicFollowingBehavior("BasicFollowingBehavior", "1: une meilleur expliquation est bienvenue");
