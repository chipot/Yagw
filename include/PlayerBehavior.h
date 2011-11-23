#ifndef PLAYERBEHAVIOR_H
#define PLAYERBEHAVIOR_H

#include <QGraphicsScene>

#include "FireBehavior.h"
#include "Shuriken.h"

class PlayerBehavior;

typedef void(PlayerBehavior::*fireLauncher)();

class PlayerBehavior : public Behavior, public QWidget
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

public:
    PlayerBehavior();
    void behave(Entity*);
    void sendEvent(QEvent *);

    void keyPressEvent( QKeyEvent * event );
    void keyReleaseEvent( QKeyEvent * event );


private :

    int  calcRotation();
    void fire();
    void fireLvl1();
    void fireLvl2();
    void fireLvl3();


};

uint qHash(QPointF const &ptr);


#endif // PLAYERBEHAVIOR_H
