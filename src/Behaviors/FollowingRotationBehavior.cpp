#include "Registry.h"

#include "Behaviors/FollowingRotationBehavior.h"
#include "Behaviors/BasicFollowingBehavior.h"

void FollowingRotationBehavior::rotate()
{
    if (entity) {
        QPointF direction = BasicFollowingBehavior::calcDirection(entity->pos(), target->pos());
        QPointF orientation(qCos(angle*PI/180), qSin(angle*PI/180));
        qreal rotation = FollowingRotationBehavior::calcAngle(QVector2D(orientation), QVector2D(direction));
        if (qFloor(rotation) < entity->getRotationSpeed())
            return;
        int sign = qCos(rotation*PI/180) >= 0 ? -1 : 1;
        entity->setRotation(sign*entity->getRotationSpeed());
        angle += entity->getRotationSpeed()*sign;
    }

}

qreal FollowingRotationBehavior::calcAngle(QVector2D u, QVector2D v) {

    qreal lower = u.length() * v.length();
    qreal dotprod = QVector2D::dotProduct(u, v);
    qreal alphacos = dotprod / lower + 0.0000001f;
    qreal alpharad = qAcos(alphacos);
    qreal alpha = alpharad * (180 / PI);

    return alpha;
}



void FollowingRotationBehavior::init() {
    if (entity)
        entity->setRotationSpeed(3);
}

Registry<RotationBehavior>::Add<FollowingRotationBehavior> FollowingRotationBehavior("FollowingRotationBehavior", "2: une meilleur expliquation est bienvenue");
