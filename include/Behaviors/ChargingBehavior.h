#ifndef CHARGINGBEHAVIOR_H
#define CHARGINGBEHAVIOR_H

#include <QTimer>
#include "Behaviors/BasicFollowingBehavior.h"

class ChargingBehavior : public QObject, public BasicFollowingBehavior
{
    Q_OBJECT
private :
    QPointF direction;
    QTimer directionUpdatingTimer;
public :
    ChargingBehavior(Entity *ent = 0, Entity *t = 0, int s = 100) : BasicFollowingBehavior(ent, t, s), direction(QPointF(0,0)) {
    }
    virtual ~ChargingBehavior(){}
    void move();
    void init();
    ChargingBehavior *copy();

public slots :
    void updateDirection();
};

#endif // CHARGINGBEHAVIOR_H
