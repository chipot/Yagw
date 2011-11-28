#include "SimpleFollowingBehavior.h"
#include "EntityFactory.h"
#include <QVector2D>
#include <QtCore/qmath.h>

static const float Pi = 3.14159f;

SimpleFollowingBehavior::SimpleFollowingBehavior() : EnnemyBehavior() {
    rotationSpeed = 0;
    moveSpeed = 1;
    direction = QPointF(0,0);
    growingUp = true;
    ent = NULL;
    actualSize = 1.0;
    maxSize = 1.5;
    growingTimeLength = 2000;
    startGrowingUpTimer();
}

void SimpleFollowingBehavior::behave(Entity *entity) {
    ent = entity;

    updateDirection(entity->pos(), playerPos());
    QPointF move = direction*moveSpeed;
    entity->setMove(move);
    entity->setRotation(rotationSpeed);
    growUp();
}

FollowingPacmanBehavior::FollowingPacmanBehavior() : SimpleFollowingBehavior() {
}

void FollowingPacmanBehavior::behave(Entity *entity) {
    ent = entity;

    QVector2D u(this->direction);
    QVector2D v(this->playerPos() - entity->pos());

    qreal dotprod = QVector2D::dotProduct(u, v);
    qreal lower = u.length() * v.length();
    qreal alphacos = dotprod / lower + 0.0000001f;
    qreal alpharad = qAcos(alphacos);
    qreal alpha = alpharad * (180 / Pi);

    qreal usqx = qPow(u.x(), 2);
    qreal usqy = qPow(u.y(), 2);
    qreal unorm = qSqrt(usqx + usqy);

    qreal vsqx = qPow(v.x(), 2);
    qreal vsqy = qPow(v.y(), 2);
    qreal vnorm = qSqrt(vsqx + vsqy);

    /*
    qDebug() << "{"; 
    qDebug() << "direction = "<< this->direction;
    qDebug() << "player pos = " << this->playerPos() << "entity pos =" << entity->pos();
    qDebug() << "u =" << u << "unrom=" << unorm << "length=" << u.length();
    qDebug() << "v =" << v << "vnorm=" << vnorm << "length=" << v.length();
    qDebug() << "dotprod =" << dotprod;
    qDebug() << "lower =" << lower;
    qDebug() << "alphacos =" << alphacos << "alpharad =" << alpharad << "alpha =" << alpha;
    qDebug() << "}"; 
    */

    //Call the superclass behave method
    SimpleFollowingBehavior::behave(entity);
}
