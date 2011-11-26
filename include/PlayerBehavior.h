#ifndef PLAYERBEHAVIOR_H
#define PLAYERBEHAVIOR_H

#include <QGraphicsScene>
#include <QTimeLine>
#include <QDebug>

#include "YagwScene.h"
#include "FireBehavior.h"

class PlayerBehavior;

typedef void(PlayerBehavior::*fireLauncher)();

class PlayerBehavior : public QObject, public Behavior
{
    Q_OBJECT
    private:
    int fireLevel;
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
    Entity *createFire(QPointF);
    void fire();
    void fireLvl1();
    void fireLvl2();
    void fireLvl3();

signals :
    void playerMoved();
    void phase0();

public slots:
    void keyPressEvent( QKeyEvent * event );
    void keyReleaseEvent( QKeyEvent * event );
};

uint qHash(QPointF const &ptr);


#endif // PLAYERBEHAVIOR_H
