#ifndef PLAYERBEHAVIOR_H
#define PLAYERBEHAVIOR_H

#include <QGraphicsScene>
#include <QTimeLine>

#include "FireBehavior.h"
#include "Shuriken.h"
#include "Ship.h"

class PlayerBehavior;

typedef void(PlayerBehavior::*fireLauncher)();

class PlayerBehavior : public Behavior
{
private:
    int fireLevel;
    int angle;
    int rotationSpeed;
    QPointF move;
    QPointF fireDirection;
    QHash<QPointF, int> directions;
    QList<fireLauncher> fl;
    Entity  *entityTemp;
    QTimeLine timeline;

public:
    PlayerBehavior();
    virtual ~PlayerBehavior(){}
    void behave(Entity*);
    void sendEvent(QEvent *);

private :
    int  calcRotation();
    void fire();
    void fireLvl1();
    void fireLvl2();
    void fireLvl3();

public slots:
    void keyPressEvent( QKeyEvent * event );
    void keyReleaseEvent( QKeyEvent * event );
};

uint qHash(QPointF const &ptr);


#endif // PLAYERBEHAVIOR_H
