#ifndef GAMEPROCESSOR_H
#define GAMEPROCESSOR_H

#include <QTimer>
#include <QVector2D>
#include <QVector>
#include <QPair>

#include "YagwScene.h"

#include "Entities/Pacman.h"

#define WINSIZE_X 1000
#define WINSIZE_Y 1000

#include "ConfManager.h"
#include "GameIA.h"

class GameIA;

class GameProcessor : public QObject
{
    Q_OBJECT
 private :
    enum _dir
    {
      R,
      L,
      T,
      B
    };
    YagwScene       &scene;
    Entity          *player;
    QList<Entity*>  entities;
    QList<Entity*>  fire;
    QVector<QPair<GameProcessor::_dir, Entity*> *>  walls;
    QVector<Entity*> lives;
    int playerLifes;
    unsigned int turn;
    QTimer *gameTimer;
    QGraphicsSimpleTextItem * disclaimer;
    QGraphicsSimpleTextItem * score;
    GameIA      gia;
    ConfManager  cfg;

 public :
    GameProcessor(YagwScene &ygwscene);
    ~GameProcessor(){}
    void setPlayer();
    void start(int = 1000 / 60);
    void spawnEntity(Entity*, QPointF);
    void affDelimiters();
    void affGrid();
    ConfManager *getConfig();
    void setBackgroundImage();
  private :

    void displayLifes();
    void createDisclaimer(const QString &);
    void newGridVertical(char*, int);
    void playerDead();
    bool isWall(const Entity *);
    void stop();
    void checkCollidings();
    void setBloom();

public slots:
    void keyPressEvent( QKeyEvent * );
    void loadFire(Entity*);
    void loadEntity(Entity*);
    void advance();
};



#endif // GAMEPROCESSOR_H
