#ifndef ENNEMYBEHAVIOR_H
#define ENNEMYBEHAVIOR_H

#include <QVector2D>
#include <QTimer>
#include "Behavior.h"


class EnnemyBehavior : public QObject, public Behavior
{
Q_OBJECT
protected :
    Entity *ent;
    int moveSpeed;
    int rotationSpeed;
    QPointF direction;
    int growingTimeLength;
    bool growingUp;
    float actualSize;
    float maxSize;

public :
    EnnemyBehavior();
    virtual ~EnnemyBehavior(){}
    void behave(Entity *entity);
    void setDirection(QPointF dir);
    void setRotationSpeed(int);
    void updateDirection(QPointF, QPointF);
    void startGrowingUpTimer();

protected :
    void growUp();

public slots :
    void changeSize();
};



#endif // ENNEMYBEHAVIOR_H
