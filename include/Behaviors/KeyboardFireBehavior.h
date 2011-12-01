#ifndef KEYBOARDFIREBEHAVIOR_H
#define KEYBOARDFIREBEHAVIOR_H

#include <QPointF>
#include <QKeyEvent>
#include <QTime>
#include <QVector2D>

#include "Behaviors.h"

class KeyboardFireBehavior : public QObject, public ShootBehavior
{
Q_OBJECT
protected :
    QPointF fireDirection;
    QTime time;
    int fireFrequency;

public :
    KeyboardFireBehavior(int fireFrequency = 150);
    virtual ~KeyboardFireBehavior();
    void setFireFrequency(int frequency);
    void shoot();

protected:
    Entity *createFire(QPointF);
    virtual void fire();

signals :
    void fireLaunched(Entity*);

public slots:
    void keyPressEvent( QKeyEvent * event );
    void keyReleaseEvent( QKeyEvent * event );
};


#endif // KEYBOARDFIREBEHAVIOR_H
