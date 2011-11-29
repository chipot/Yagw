#ifndef KEYBOARDROTATIONBEHAVIOR_H
#define KEYBOARDROTATIONBEHAVIOR_H

#include <QKeyEvent>

#include "Behaviors.h"

class KeyboardRotationBehavior : public QObject, public RotationBehavior
{
    Q_OBJECT
private :
    QHash<QPointF, int> directions;
    int angle;
    QPointF orientation;

public :
    KeyboardRotationBehavior();
    virtual ~KeyboardRotationBehavior();
    void rotate();
    void setEntity(Entity*);
    void init();
private :
    int calcRotation();

public slots:
    void keyPressEvent( QKeyEvent * event );
    void keyReleaseEvent( QKeyEvent * event );

};

uint qHash(QPointF const &ptr);


#endif // KEYBOARDROTATIONBEHAVIOR_H
