#ifndef GAMEPROCESSOR_H
#define GAMEPROCESSOR_H

#include <QTimer>
#include <QVector2D>

#include "PlayerBehavior.h"
#include "FireBehavior.h"
#include "SimpleFollowingBehavior.h"
#include "YagwScene.h"


class GameProcessor : public QObject
{
    Q_OBJECT

private :
    PlayerBehavior  *playerBehavior;
    YagwScene       &scene;
    Entity          *player;
    QList<Entity*>  entities;
    QList<Behavior*> listeners;

public :
    GameProcessor(YagwScene &ygwscene);
    ~GameProcessor(){}
    void setPlayer(const char *name);
    void start(void);
    void generateEntity(const char *name);
    void spawnEntity(Entity*, QPointF);

private :
    QPointF randomDirection();
    QPointF randomPosition();

public slots:
    void loadEntity(Entity*);
    void spawnEnnemy1();
    void updatePlayerPosition();
};



#endif // GAMEPROCESSOR_H
