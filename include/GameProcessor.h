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
    QList<Entity*>  fire;
    int playerLifes;
    QTimer *ennemy1Timer;
    QTimer *gameTimer;

public :
    GameProcessor(YagwScene &ygwscene);
    ~GameProcessor(){}
    void setPlayer();
    void start(int);
    void generateEntity(const char *name);
    void spawnEntity(Entity*, QPointF);

private :
    QPointF randomDirection();
    QPointF randomPosition();
    void playerDead();
    void stop();
public slots:
    void loadFire(Entity*);
    void loadEntity(Entity*);
    void spawnEnnemy1();
    void checkCollidings();
};



#endif // GAMEPROCESSOR_H
