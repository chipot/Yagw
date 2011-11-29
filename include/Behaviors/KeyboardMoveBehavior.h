#ifndef KEYBOARDMOVEBEHAVIOR_H
#define KEYBOARDMOVEBEHAVIOR_H

#include <QPointF>
#include <QKeyEvent>
#include <QTime>
#include <QVector2D>

#include "Behaviors.h"

class KeyboardMoveBehavior : public QObject, public MoveBehavior
{
Q_OBJECT
private :
    QPointF displacement;
    int maxSpeed;
    QTime time;

public :
    KeyboardMoveBehavior();
    virtual ~KeyboardMoveBehavior();
    void move();
    void init();

public slots:
    void keyPressEvent( QKeyEvent * event );
    void keyReleaseEvent( QKeyEvent * event );
};

#endif // KEYBOARDMOVEBEHAVIOR_H
