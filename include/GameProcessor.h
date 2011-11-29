#ifndef GAMEPROCESSOR_H
#define GAMEPROCESSOR_H

#include <QTimer>
#include <QVector2D>
#include <QVector>
#include <QPair>

#include "YagwScene.h"
#include "FireBehavior.h"

#include "Entities/Pacman.h"

#define WINSIZE_X 1000
#define WINSIZE_Y 1000

class GameProcessor : public QObject
{
    Q_OBJECT

private :
    enum _dir{R,L,T,B};
    YagwScene       &scene;
    Entity          *player;
    QList<Entity*>  entities;
    QList<Entity*>  fire;
    QVector<QPair<GameProcessor::_dir, Entity*> *>  walls;
    QVector<Entity*> lives;
    int playerLifes;
    QTimer *ennemy1Timer;
    QTimer *ennemy2Timer;
    QTimer *gameTimer;
    QGraphicsSimpleTextItem * disclaimer;
    QGraphicsSimpleTextItem * score;

public :
    GameProcessor(YagwScene &ygwscene);
    ~GameProcessor(){}
    void setPlayer();
    void start(int = 1000 / 60);
    void generateEntity(const char *name);
    void spawnEntity(Entity*, QPointF);
    void affDelimiters();
    void affGrid();

private :
    void displayLifes();
    void createDisclaimer(const QString &);
    QPointF randomDirection();
    QPointF randomPosition();
    void newGridVertical(char *name, FireBehavior *GridLineBehavior, int i);
    void playerDead();
    bool isWall(const Entity *);
    void stop();

public slots:
    void keyPressEvent( QKeyEvent * );
    void loadFire(Entity*);
    void loadEntity(Entity*);
    void spawnEnnemy1();
    void spawnEnnemy2();
    void checkCollidings();
};



#endif // GAMEPROCESSOR_H
