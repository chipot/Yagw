#ifndef GAMEPROCESSOR_H
#define GAMEPROCESSOR_H

#include "PlayerBehavior.h"
#include "YagwScene.h"

class GameProcessor
{
public :
    GameProcessor(YagwScene &ygwscene);
    void start(void) const;


private :
    PlayerBehavior  *playerBehavior;
    YagwScene       &scene;
    Entity          *player;
    QList<Entity*>  entities;

};

#endif // GAMEPROCESSOR_H
