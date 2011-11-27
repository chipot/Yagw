#ifndef GAMEPROCESSOR_H
#define GAMEPROCESSOR_H

#include <QTimer>
#include <QVector2D>

#include "PlayerBehavior.h"
#include "FireBehavior.h"
#include "SimpleFollowingBehavior.h"
#include "YagwScene.h"

#define WINSIZE_X 1000
#define WINSIZE_Y 1000

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
    void affDelimiters();
    void affGrid();

private :
    QPointF randomDirection();
    QPointF randomPosition();
    void newGridVertical(char *name, FireBehavior *GridLineBehavior, int i);
    void playerDead();
    void stop();
public slots:
    void loadFire(Entity*);
    void loadEntity(Entity*);
    void spawnEnnemy1();
    void checkCollidings();
};



#endif // GAMEPROCESSOR_H
