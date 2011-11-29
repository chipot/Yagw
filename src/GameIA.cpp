#include "EntityFactory.h"
#include "Registry.h"
#include "GameIA.h"
#include "WallBehavior.h"
#include "Behaviors/BasicFollowingBehavior.h"
#include "Behaviors/KeyboardFireBehavior.h"
#include "Behaviors/KeyboardMoveBehavior.h"
#include "Behaviors/KeyboardRotationBehavior.h"
#include "Profile.h"
#include "PlayerBehavior.h"
#include "FireBehavior.h"
#include "SimpleFollowingBehavior.h"
#include "GameProcessor.h"

GameIA::GameIA(GameProcessor &g, int w, int h, Entity *&p)
  :game(g), width(w), height(h), player(p)
{

}

QPointF GameIA::randomDirection() {
    float x = ((rand()%2000) - 1000);
    float y = ((rand()%2000) - 1000);
    x /= 1000.0;
    y /= 1000.0;
    QPointF random(x, y);
    return random;
}

QPointF GameIA::randomPosition() {
    int posx = (rand() % (long int)this->width) - (long int)this->width/2;
    int posy = (rand() % (long int)this->height) - (long int)this->height/2;
    QPointF random(posx, posy);
    return random;
}


int  GameIA::calcLevel(const  int i)
{
  return 120 - (i / 40) + 1;
}

void GameIA::advance(const  int turn, const  int score)
{
  int level = this->calcLevel(score);

  if (!(turn % level))
    {
      Entity *entity = EntityFactory::getEntity("greensquare");
      BasicFollowingBehavior *moveBehavior = new BasicFollowingBehavior(entity, player);
      Profile *profile = new Profile(moveBehavior);
      entity->setProfile(profile);
      game.spawnEntity(entity, randomPosition());
    }
}



    // Entity *entity = EntityFactory::getEntity("pacman");

    // FollowingRotationBehavior *rotationBehavior = new FollowingRotationBehavior(entity, player, 270);
    // BasicFollowingBehavior *moveBehavior = new BasicFollowingBehavior(entity, player);

    // Profile *profile = new Profile(moveBehavior, rotationBehavior);
    // QPointF entityPosition = randomPosition();
    // entity->setScene(&scene);
    // entity->setProfile(profile);
    // spawnEntity(entity, entityPosition);
    // entities << entity;
