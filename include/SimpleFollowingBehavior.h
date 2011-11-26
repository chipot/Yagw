#ifndef SIMPLEFOLLOWINGBEHAVIOR_H
#define SIMPLEFOLLOWINGBEHAVIOR_H

#include <QVector2D>
#include <QTimer>
#include "Behavior.h"


class SimpleFollowingBehavior : public QObject, public Behavior
{
    Q_OBJECT
    private:
    Entity *ent;
    int moveSpeed;
    int rotationSpeed;
    QPointF direction;
    int growingTimeLength;
    bool growingUp;
    float actualSize;
    float maxSize;

public :
    SimpleFollowingBehavior();
    virtual ~SimpleFollowingBehavior(){}
    void behave(Entity *entity);
    void setDirection(QPointF dir);
    void setRotationSpeed(int);
    void updateDirection(QPointF, QPointF);

private :
    void growUp();

public slots :
    void changeSize();
};

#endif // SIMPLEFOLLOWINGBEHAVIOR_H
