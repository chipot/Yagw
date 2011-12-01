#include "ProfileFactory.h"
#include "EntityFactory.h"
#include "Registry.h"
#include "GameIA.h"
#include "Behaviors/BasicFollowingBehavior.h"
#include "Behaviors/KeyboardFireBehavior.h"
#include "Behaviors/KeyboardMoveBehavior.h"
#include "Behaviors/KeyboardRotationBehavior.h"
#include "Profile.h"
#include "GameProcessor.h"


GameIA::GameIA(GameProcessor &g, int w, int h, Entity *&p)
    :game(g), profileFactory(new ProfileFactory()), width(w), height(h), player(p), level(0)
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

void  GameIA::calcLevel(const  int i)
{
  this->level = (i / 100 > 10 ? 10 : i / 100);
}

void GameIA::advance(const  int turn, const  int score)
{
  int freq = (120 - (score / 40) + 1 <= 0 ? 1 : 120 - (score / 40) + 1);
  this->calcLevel(score);

  if (!(turn % freq))
    {
      Entity *entity = EntityFactory::getRandom(this->level);
      if (!entity)
        return;
      entity->setProfile(
        new Profile(MoveBehaviorFactory::getRandom(this->level, this->player),
                    RotationBehaviorFactory::getRandom(this->level, this->player),
                    ShootBehaviorFactory::getRandom(this->level),
                    TransformationBehaviorFactory::getRandom(this->level)));
      this->game.spawnEntity(entity, randomPosition());
    }
}

void GameIA::setProfile(const char *name, Profile *profile) {
    profileFactory->StoreProfile(name, profile);
}

void GameIA::designProfiles() {

}

