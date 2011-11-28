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
private :
    QPointF fireDirection;
    QTime time;
    int fireFrequency;

public :
    KeyboardFireBehavior();
    virtual ~KeyboardFireBehavior(){}
    void setFireFrequency(int frequency);
    void fire();

private:
    Entity *createFire(QPointF);

signals :
    void fireLaunched(Entity*);

public slots:
    void keyPressEvent( QKeyEvent * event );
    void keyReleaseEvent( QKeyEvent * event );
};


#endif // KEYBOARDFIREBEHAVIOR_H
