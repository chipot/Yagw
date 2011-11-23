#ifndef FIREBEHAVIOR_H
#define FIREBEHAVIOR_H

#include "Behavior.h"
#include <QPointF>

class FireBehavior : public Behavior
{
private :
    int rotationSpeed;
    QPointF direction;
public:
    FireBehavior();
    void behave(Entity*);
    void sendEvent(QEvent*);
    void setDirection(QPointF &dir);
    void keyPressEvent( QKeyEvent * event );
    void keyReleaseEvent( QKeyEvent * keyEvent );

};

#endif // FIREBEHAVIOR_H
