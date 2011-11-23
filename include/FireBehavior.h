#ifndef FIREBEHAVIOR_H
#define FIREBEHAVIOR_H

#include "Behavior.h"
#include <QPointF>

class FireBehavior : public Behavior
{
private :
    int rotationSpeed;
    int moveSpeed;
    QPointF direction;
public:
    FireBehavior();
    void behave(Entity*);
    void sendEvent(QEvent*);
    void setDirection(QPointF &dir);
};

#endif // FIREBEHAVIOR_H
