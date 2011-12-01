#include "ProfileFactory.h"
#include "EntityFactory.h"
#include "Registry.h"
#include "GameIA.h"
#include "Behaviors/BasicFollowingBehavior.h"
#include "Behaviors/KeyboardFireBehavior.h"
#include "Behaviors/KeyboardMultipleFireBehavior.h"
#include "Behaviors/KeyboardMoveBehavior.h"
#include "Behaviors/KeyboardRotationBehavior.h"
#include "Behaviors/GrowingBehavior.h"
#include "Behaviors/FollowingRotationBehavior.h"
#include "Behaviors/SimpleMoveBehavior.h"
#include "Behaviors/ChargingBehavior.h"
#include "Behaviors/BasicRotationBehavior.h"
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
  game.getPlayerFire()->setNumber(this->level+1);
}

void GameIA::advance(const  int turn, const  int score)
{
  int freq = (70 - (score / 40) + 1 <= 0 ? 1 : 70 - (score / 40) + 1);

  this->calcLevel(score);

  if (!(turn % freq))
    {
      Entity *entity = EntityFactory::getRandom(this->level);
      if (!entity)
        return;
      ConfManager *M = game.getConfig();
      QString profileName = M->getProfileIndex(entity->getIndex());
      Profile *P = profileFactory->getCopy(profileName);
      if (P != 0)
        entity->setProfile(P); 
      /*
      new Profile(MoveBehaviorFactory::getRandom(this->level, this->player),
                  RotationBehaviorFactory::getRandom(this->level, this->player),
                  ShootBehaviorFactory::getRandom(this->level),
                  TransformationBehaviorFactory::getRandom(this->level)));
      */
      this->game.spawnEntity(entity, randomPosition());
    }
}

void GameIA::setProfile(QString name, Profile *profile) {
    profileFactory->StoreProfile(name, profile);
}

void GameIA::designProfiles() {
    // Profile : "following"

    BasicFollowingBehavior *following = new BasicFollowingBehavior(0, this->player);
    setProfile(QString("following"), new Profile(following->copy()));

    // Profile : "followingGrowing"

    setProfile(QString("followingGrowing"), new Profile(following->copy(), 0, 0, new GrowingBehavior()));

    // Profile : "followingRotating"
    setProfile(QString("followingRotating"), new Profile(new BasicFollowingBehavior(0, this->player, 110), new FollowingRotationBehavior(0, this->player, 270)));

    // Profile : "immobileFiring"
    setProfile(QString("immobileFiring"), new Profile(0, 0, 0, 0));

    // Profile : "charging"
    setProfile(QString("charging"), new Profile(new ChargingBehavior(0, this->player, 400)));

    // Profile : "followingGrowing2"
    setProfile(QString("followingGrowing2"), new Profile(new BasicFollowingBehavior(0, this->player, 110), new BasicRotationBehavior(0, 10), 0, new GrowingBehavior(1000, 0.6)));

    // Profile : "expanding"
    setProfile(QString("expanding"), new Profile(0, 0, 0, new GrowingBehavior(2500, 10)));
}

