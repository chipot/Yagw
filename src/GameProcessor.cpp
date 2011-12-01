#include <QString>
#include <complex>
#include "GameProcessor.h"
#include "Registry.h"
#include "EntityFactory.h"
#include "Score.h"
#include "Entity.h"
#include "Profile.h"
#include "ConfManager.h"

#include "Behaviors/BasicFollowingBehavior.h"
#include "Behaviors/FollowingRotationBehavior.h"
#include "Behaviors/KeyboardMultipleFireBehavior.h"
#include "Behaviors/KeyboardMoveBehavior.h"
#include "Behaviors/KeyboardRotationBehavior.h"
#include "Behaviors/GrowingBehavior.h"

GameProcessor::GameProcessor(YagwScene &ygws)
  : scene(ygws),
    player(0),
    disclaimer(0),
    gia(*this, ygws.width(), ygws.height(), player),
    cfg(ConfManager("config.cfg")),
    playerFire(0)
{
    QObject::connect(&scene, SIGNAL(newEntity(Entity*)), this, SLOT(loadEntity(Entity*)));
    QObject::connect(&scene, SIGNAL(newFire(Entity*)), this, SLOT(loadFire(Entity*)));
    QObject::connect(&scene, SIGNAL(phase2()), this, SLOT(advance()));
    GameProcessor::affDelimiters();
    QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)), this, SLOT(keyPressEvent(QKeyEvent*)));
    GameProcessor::createDisclaimer("Press RETURN to start");


    QGraphicsSimpleTextItem *txt = this->scene.addSimpleText("Lives:");
// attention on perd le pointeur. a changer.
    QFont font;
    QPen pen(Qt::red, 1, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin);
    font.setBold(true);
    font.setPointSize(20);
    txt->setFont(font);
    txt->setBrush(Qt::red);
    txt->setPen(pen);
    txt->setPos(WINSIZE_X / 2  + 5,- WINSIZE_Y / 2 + 10);
    QString str("Score:\n");
    str += QString::number(Score::get_instance()->getScore()) + QString::fromAscii("\nMax:\n") + QString::number(Score::get_instance()->getMax());
    txt = this->scene.addSimpleText(str);
    txt->setFont(font);
    txt->setBrush(Qt::red);
    txt->setPen(pen);
    txt->setPos(WINSIZE_X / 2  + 5,- WINSIZE_Y / 2 + 200);
    this->score = txt;
    //GameProcessor::affGrid();
}

void GameProcessor::keyPressEvent( QKeyEvent * e)
{
  if (e->key() == Qt::Key_Return)
    {
      QObject::disconnect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)), this, SLOT(keyPressEvent(QKeyEvent*)));
      this->start();
    }
}


void GameProcessor::createDisclaimer(const QString &s)
 {
   QFont font;
   font.setBold(true);
   font.setPointSize(42);
   delete this->disclaimer;
   this->disclaimer = scene.addSimpleText(s, font);
   this->disclaimer->setBrush(Qt::white);
   QPen pen(Qt::white, 3, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin);
   this->disclaimer->setPen(pen);
   this->disclaimer->setPos(-WINSIZE_X / 4, 0);
 }

void GameProcessor::advance()
{
  QGraphicsView *ptr = 0x0;
  this->gia.advance(++(this->turn), Score::get_instance()->getScore());
  this->checkCollidings();
  this->displayLifes();
  QString str("Score:\n");
  Score *scoreptr = Score::get_instance();
  str += QString::number(scoreptr->getScore())
      + QString::fromAscii("\nMax:\n")
      + QString::number(scoreptr->getMax());
  this->score->setText(str);
  QList<QGraphicsView*> views = this->scene.views();
  foreach(ptr, views)
  {
    if (this->player != 0)
      ptr->centerOn(this->player);
  }
}

void GameProcessor::setPlayer()
{

    KeyboardMoveBehavior *playerMoveBehavior = new KeyboardMoveBehavior();
    KeyboardMultipleFireBehavior *playerShootBehavior = 
        new KeyboardMultipleFireBehavior(150, 1, 7);
    KeyboardRotationBehavior *playerRotationBehavior = 
        new KeyboardRotationBehavior();

    QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)),
                     playerMoveBehavior, SLOT(keyPressEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyReleaseEvent(QKeyEvent*)),
                     playerMoveBehavior, SLOT(keyReleaseEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)),
                     playerRotationBehavior, SLOT(keyPressEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyReleaseEvent(QKeyEvent*)),
                     playerRotationBehavior, SLOT(keyReleaseEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)),
                     playerShootBehavior, SLOT(keyPressEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyReleaseEvent(QKeyEvent*)),
                     playerShootBehavior, SLOT(keyReleaseEvent(QKeyEvent*)));

    Profile *playerProfile = new Profile(playerMoveBehavior, playerRotationBehavior, playerShootBehavior);
    player = EntityFactory::getEntity("spaceship");
    qDebug() << "Player addr:" << (void*)player;
    if (player != NULL) {
        player->setProfile(playerProfile);
        scene.addItem(player);
        player->setScene(&scene);
        player->setFlag(QGraphicsItem::ItemIsFocusable, true);
        scene.setFocusItem(player);
    }
    playerFire = playerShootBehavior;
 }


void GameProcessor::stop()
{
  Score::get_instance()->saveScore();
  this->player = 0;
  gameTimer->stop();
  gameTimer->disconnect();
  delete gameTimer;
  QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)), this, SLOT(keyPressEvent(QKeyEvent*)));
  this->createDisclaimer("        Game Over\nPress RETURN to start");
}

void GameProcessor::displayLifes()
{
  int i = 0;
  if (this->lives.size() < this->playerLifes + 1)
    this->lives.resize(this->playerLifes + 1);
  for (; i < this->playerLifes; ++i)
    {
      if (!this->lives[i])
        {
          this->lives[i] = EntityFactory::getEntity("spaceship");
          this->lives[i]->setLives(-1);
          this->lives[i]->setProfile(new Profile(0,0,0,0));
          this->lives[i]->setPos(WINSIZE_X / 2  + this->lives[i]->boundingRect().width(),
                                 - WINSIZE_Y / 2 + 90 - (5 + this->lives[i]->boundingRect().height()) * i);
          this->scene.addItem(this->lives[i]);
        }
    }
  while (this->lives[i])
    {
      this->scene.removeItem(lives[i]);
      delete this->lives[i];
      this->lives[i] = 0;
      ++i;
    }
}


void GameProcessor::start(int framePerSecond)
{
  cfg.parseFile();
  this->turn = 0;
  this->playerLifes = 3;
  this->displayLifes();
  scene.removeItem(disclaimer);
  delete this->disclaimer;
  this->disclaimer = 0;
  Score::get_instance()->reset();
  gameTimer = new QTimer();
  gameTimer->connect(gameTimer, SIGNAL(timeout()), &scene, SLOT(advance()));
  gameTimer->start(framePerSecond);
  this->setPlayer();
  this->gia.designProfiles();
}

void GameProcessor::spawnEntity(Entity *entity, QPointF position) {
  scene.addItem(entity);
  entity->moveBy(position.x(), position.y());
  entities << entity;
  entity->setScene(&scene);
}

void GameProcessor::loadEntity(Entity *entity) {
    entities << entity;
}

void GameProcessor::loadFire(Entity *entity) {
    fire << entity;
}



void GameProcessor::playerDead() {
  QList<Entity*> to_delete;
  QGraphicsItem *item;

  to_delete << this->fire;
  to_delete << this->entities;
  foreach(item, to_delete)
    {
      scene.removeItem(item);
      delete item;
    }
  this->fire.erase(this->fire.begin(), this->fire.end());
  this->entities.erase(this->entities.begin(), this->entities.end());

  scene.removeItem(this->player);
  delete this->player;
  if (--playerLifes > 0) {
    this->setPlayer();
    this->gia.designProfiles();
  }
  else
    this->stop();
  this->displayLifes();
}

void GameProcessor::checkCollidings()
{
  QList<QGraphicsItem*> to_delete;
  QGraphicsItem *item = 0;
  int size = 0;

  foreach(item, this->fire)
  {
    QList<QGraphicsItem*> const &collideList = item->collidingItems();
    QGraphicsItem *collideIt = 0;
    foreach (collideIt, collideList)
    {
      Entity const *currentEntity = static_cast<Entity*>(collideIt);
      if (currentEntity->getType() != Entity::bullet)
        to_delete += collideIt;
    }
    if ((size != to_delete.size()) || (std::abs(item->x()) > WINSIZE_X / 2)
         || (std::abs(item->y()) > WINSIZE_Y / 2))
    {
      to_delete << item;
      size = to_delete.size();
    }
  }

  foreach(item, to_delete)
  {
    Entity *currentEntity = static_cast<Entity*>(item); // not const because of call to die
    if (currentEntity == this->player || currentEntity->die() == false)
      continue;
    if (currentEntity->getType() == Entity::bullet)
      {
        scene.removeItem(item);
        this->fire.removeOne(currentEntity);
        delete currentEntity;
      }
    else
      {
        this->entities.removeOne(currentEntity);
        currentEntity->explode();
      }
  }

  QPair<GameProcessor::_dir, Entity*> const * pair = 0;
  foreach(pair, walls)
  {
      foreach(item, pair->second->collidingItems())
      {
        Entity const * currentEntity = static_cast<Entity*>(item);
        if (isWall(currentEntity))
          continue;
        switch (pair->first)
        {
          case GameProcessor::L:
            item->moveBy(std::abs(currentEntity->getMove().x()) + 1, 0);
            break;
          case GameProcessor::R:
            item->moveBy(-(std::abs(currentEntity->getMove().x()) + 1), 0);
            break;
          case GameProcessor::B:
            item->moveBy(0, -(std::abs(currentEntity->getMove().y()) + 1));
            break;
          case GameProcessor::T:
            item->moveBy(0, (std::abs(currentEntity->getMove().y()) + 1));
            break;
          default:
            break;
        }
      }
  }

  if (player != 0 && player->shielded() == false)
    {
      QList<QGraphicsItem*> const &collidingItems = this->player->collidingItems();
      foreach(item, collidingItems)
        {
          Entity *currentEntity = static_cast<Entity*>(item);
          if (currentEntity->shielded() == false)
            {
              scene.removeItem(item);
              this->entities.removeOne(currentEntity);
              delete item;
              this->playerDead();
              break;
            }
        }
    }
}

bool    GameProcessor::isWall(const Entity *e)
{
  QPair<GameProcessor::_dir, Entity*> * pair;
  foreach(pair, walls)
    if (pair->second == e)
      return true;
  return false;
}


void GameProcessor::affDelimiters() {

    Entity *delimDown = EntityFactory::getEntity("gamedelimiterhorizontal");
    delimDown->setProfile(new Profile(0,0,0,0));
    this->scene.addItem(delimDown);
    delimDown->setScene(&(this->scene));
    delimDown->moveBy(-1 * WINSIZE_X/2, WINSIZE_Y/2);
    delimDown->setLives(-1);
    Entity *delimUp = EntityFactory::getEntity("gamedelimiterhorizontal");
    delimUp->setProfile(new Profile(0,0,0,0));
    this->scene.addItem(delimUp);
    delimUp->setScene(&(this->scene));
    delimUp->moveBy(-1 * WINSIZE_X/2, -1 * WINSIZE_Y/2);
    delimUp->setLives(-1);
    Entity *delimLeft = EntityFactory::getEntity("gamedelimitervertical");
    delimLeft->setProfile(new Profile(0,0,0,0));
    this->scene.addItem(delimLeft);
    delimLeft->setScene(&(this->scene));
    delimLeft->moveBy(-1 * WINSIZE_X/2, -1 * WINSIZE_Y/2);
    delimLeft->setLives(-1);
    Entity *delimRight = EntityFactory::getEntity("gamedelimitervertical");
    delimRight->setProfile(new Profile(0,0,0,0));
    this->scene.addItem(delimRight);
    delimRight->setScene(&(this->scene));
    delimRight->moveBy(WINSIZE_X/2, -1 * WINSIZE_Y/2);
    delimRight->setLives(-1);
    walls.append(new QPair<GameProcessor::_dir, Entity*>(GameProcessor::R, delimRight));
    walls.append(new QPair<GameProcessor::_dir, Entity*>(GameProcessor::L, delimLeft));
    walls.append(new QPair<GameProcessor::_dir, Entity*>(GameProcessor::T, delimUp));
    walls.append(new QPair<GameProcessor::_dir, Entity*>(GameProcessor::B, delimDown));
}

void GameProcessor::newGridVertical(char *name, int i)
{
    Entity *delimUp = EntityFactory::getEntity(name);
    this->scene.addItem(delimUp);
    delimUp->setScene(&(this->scene));
    delimUp->moveBy(i, -1 * WINSIZE_Y/2);
}

void GameProcessor::affGrid()
{

    /* Toutes les verticales */
    int i;
    i = -1 * WINSIZE_X/2;
    while(i < WINSIZE_X/2)
    {
        if (i != 0) //A SUPPRIMER sert à éviter le segfault des collisions
        newGridVertical((char *)"gridvert1", i);
        i += 50;
    }
    i = -1 * WINSIZE_Y/2;
    while(i < WINSIZE_Y/2)
    {
        if (i != 0) //A SUPPRIMER sert à éviter le segfault des collisions
        newGridVertical((char *)"gridvert1", i);
        i += 50;
    }
}

ConfManager *GameProcessor::getConfig() {
    return &cfg;
}

KeyboardMultipleFireBehavior *GameProcessor::getPlayerFire() {
    return playerFire;
}
