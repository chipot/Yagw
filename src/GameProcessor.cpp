#include <QString>
#include <complex>
#include "GameProcessor.h"
#include "Registry.h"
#include "EntityFactory.h"
#include "Score.h"
#include "Entity.h"
#include "WallBehavior.h"
#include "Behaviors/BasicFollowingBehavior.h"
#include "Behaviors/KeyboardFireBehavior.h"
#include "Behaviors/KeyboardMoveBehavior.h"
#include "Behaviors/KeyboardRotationBehavior.h"
#include "Profile.h"

GameProcessor::GameProcessor(YagwScene &ygws)
  : scene(ygws), player(0), disclaimer(0) {
    QObject::connect(&scene, SIGNAL(newEntity(Entity*)), this, SLOT(loadEntity(Entity*)));
    QObject::connect(&scene, SIGNAL(newFire(Entity*)), this, SLOT(loadFire(Entity*)));
    QObject::connect(&scene, SIGNAL(phase2()), this, SLOT(advance()));
    playerBehavior = NULL;
    GameProcessor::affDelimiters();
    QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)), this, SLOT(keyPressEvent(QKeyEvent*)));
    GameProcessor::createDisclaimer("Press any Key to start");


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

void GameProcessor::keyPressEvent( QKeyEvent * )
{
  QObject::disconnect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)), this, SLOT(keyPressEvent(QKeyEvent*)));
  this->start();
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
  this->checkCollidings();
  this->displayLifes();
  QString str("Score:\n");
    str += QString::number(Score::get_instance()->getScore()) + QString::fromAscii("\nMax:\n") + QString::number(Score::get_instance()->getMax());
    this->score->setText(str);
}

void GameProcessor::setPlayer()
{
    KeyboardMoveBehavior *playerMoveBehavior = new KeyboardMoveBehavior();
    KeyboardFireBehavior *playerShootBehavior = new KeyboardFireBehavior();
    KeyboardRotationBehavior *playerRotationBehavior = new KeyboardRotationBehavior();

    QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)), playerMoveBehavior, SLOT(keyPressEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyReleaseEvent(QKeyEvent*)), playerMoveBehavior, SLOT(keyReleaseEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)), playerRotationBehavior, SLOT(keyPressEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyReleaseEvent(QKeyEvent*)), playerRotationBehavior, SLOT(keyReleaseEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)), playerShootBehavior, SLOT(keyPressEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyReleaseEvent(QKeyEvent*)), playerShootBehavior, SLOT(keyReleaseEvent(QKeyEvent*)));

    Profile *playerProfile = new Profile(playerMoveBehavior, playerRotationBehavior, playerShootBehavior);

    playerBehavior = new PlayerBehavior();
    QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)), playerBehavior, SLOT(keyPressEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyReleaseEvent(QKeyEvent*)), playerBehavior, SLOT(keyReleaseEvent(QKeyEvent*)));

    player = EntityFactory::getEntity("spaceship");
    qDebug() << "player set";
    if (player != NULL) {
        player->setBehavior(playerBehavior);
        player->setProfile(playerProfile);
        scene.addItem(player);
        player->setScene(&scene);
        player->setFlag(QGraphicsItem::ItemIsFocusable, true);
        scene.setFocusItem(player);
    }
    qDebug() << "player set";
 }

QPointF GameProcessor::randomDirection() {
    float x = ((rand()%2000) - 1000);
    float y = ((rand()%2000) - 1000);
    x /= 1000.0;
    y /= 1000.0;
    QPointF random(x, y);
    return random;
}

QPointF GameProcessor::randomPosition() {
    int posx = (rand() % (long int)scene.width()) - (long int)scene.width()/2;
    int posy = (rand() % (long int)scene.height()) - (long int)scene.height()/2;
    QPointF random(posx, posy);
    return random;
}

void GameProcessor::stop()
{
  this->player = 0;
  ennemy1Timer->disconnect();
  delete ennemy1Timer;
  gameTimer->stop();
  gameTimer->disconnect();
  delete gameTimer;
  QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)), this, SLOT(keyPressEvent(QKeyEvent*)));
  this->createDisclaimer("        Game Over\nPress any key to start");
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
          this->lives[i]->setBehavior(new WallBehavior());
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
  ennemy1Timer = new QTimer();
  ennemy1Timer->connect(ennemy1Timer, SIGNAL(timeout()), this, SLOT(spawnEnnemy1()));
  ennemy1Timer->start(2500);
}

void GameProcessor::generateEntity(const char *name) {
    qDebug() << "generate Entity";
    Entity *entity = EntityFactory::getEntity(name);
    entities << entity;
}

void GameProcessor::spawnEntity(Entity *entity, QPointF position) {
  scene.addItem(entity);
    entity->moveBy(position.x(), position.y());
}

void GameProcessor::loadEntity(Entity *entity) {
    entities << entity;
}

void GameProcessor::loadFire(Entity *entity) {
    fire << entity;
}

void GameProcessor::spawnEnnemy1() {
    Entity *entity = EntityFactory::getEntity("greensquare");

    SimpleFollowingBehavior *behavior = new SimpleFollowingBehavior();
    BasicFollowingBehavior *moveBehavior = new BasicFollowingBehavior(entity, player);

    Profile *profile = new Profile(moveBehavior);
    QPointF entityPosition = randomPosition();
    entity->setScene(&scene);
    entity->setBehavior(behavior);
    entity->setProfile(profile);
    spawnEntity(entity, entityPosition);
    entities << entity;
}

/*
void GameProcessor::updatePlayerPosition() {

    QList<Entity*>::iterator it = entities.begin();
    QList<Entity*>::iterator ite = entities.end();

    for (;it != ite; ++it) {
        (*it)->setPlayerPosition(player->pos());
    }
}
*/

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
  if (--playerLifes > 0)
    this->setPlayer();
  else
    this->stop();
  this->displayLifes();
}

void GameProcessor::checkCollidings()
{
    QSet<QGraphicsItem*> to_delete;
    QList<QGraphicsItem*> used_fire;
    QGraphicsItem *item;
    int size = 0;

    foreach(item, this->fire)
      {
        to_delete += QSet<QGraphicsItem*>::fromList(item->collidingItems());
        if (size != to_delete.size() ||
            std::abs(item->x()) > WINSIZE_X / 2 ||
            std::abs(item->y()) > WINSIZE_Y / 2)
          {
            used_fire << item;
            size = to_delete.size();
          }
      }
    foreach(item, used_fire)
      {
        scene.removeItem((item));
        this->fire.removeOne(static_cast<Entity*>(item));
        delete item;
      }
    foreach(item, to_delete)
      {
        if (static_cast<Entity*>(item) == this->player || !static_cast<Entity*>(item)->die())
          continue;
        scene.removeItem(item);
        this->entities.removeOne(static_cast<Entity*>(item));
        delete item;
      }
        QPair<GameProcessor::_dir, Entity*> * pair;
    foreach(pair, walls)
      foreach(item, pair->second->collidingItems())
          {
            if (isWall(static_cast<Entity*>(item)))
              continue;
            if (pair->first == GameProcessor::L)
              item->moveBy(std::abs(static_cast<Entity*>(item)->getMove().x()) + 1, 0);
            else if (pair->first == GameProcessor::R)
              item->moveBy(-(std::abs(static_cast<Entity*>(item)->getMove().x()) + 1), 0);
            else if (pair->first == GameProcessor::B)
              item->moveBy(0, -(std::abs(static_cast<Entity*>(item)->getMove().y()) + 1));
            else if (pair->first == GameProcessor::T)
              item->moveBy(0, (std::abs(static_cast<Entity*>(item)->getMove().y()) + 1));
          }
    if (player->shielded())
        return;
    QList<QGraphicsItem*> collidingItems = this->player->collidingItems();
    if (this->player && collidingItems.size() != 0) {
        foreach(item, collidingItems) {
            if (!static_cast<Entity*>(item)->shielded()) {
                scene.removeItem((item));
                this->entities.removeOne(static_cast<Entity*>(item));
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
    delimDown->setBehavior(new WallBehavior());
    this->scene.addItem(delimDown);
    delimDown->setScene(&(this->scene));
    delimDown->moveBy(-1 * WINSIZE_X/2, WINSIZE_Y/2);
    delimDown->setLives(-1);
    Entity *delimUp = EntityFactory::getEntity("gamedelimiterhorizontal");
    delimUp->setBehavior(new WallBehavior());
    this->scene.addItem(delimUp);
    delimUp->setScene(&(this->scene));
    delimUp->moveBy(-1 * WINSIZE_X/2, -1 * WINSIZE_Y/2);
    delimUp->setLives(-1);
    Entity *delimLeft = EntityFactory::getEntity("gamedelimitervertical");
    delimLeft->setBehavior(new WallBehavior());
    this->scene.addItem(delimLeft);
    delimLeft->setScene(&(this->scene));
    delimLeft->moveBy(-1 * WINSIZE_X/2, -1 * WINSIZE_Y/2);
    delimLeft->setLives(-1);
    Entity *delimRight = EntityFactory::getEntity("gamedelimitervertical");
    delimRight->setBehavior(new WallBehavior());
    this->scene.addItem(delimRight);
    delimRight->setScene(&(this->scene));
    delimRight->moveBy(WINSIZE_X/2, -1 * WINSIZE_Y/2);
    delimRight->setLives(-1);
    walls.append(new QPair<GameProcessor::_dir, Entity*>(GameProcessor::R, delimRight));
    walls.append(new QPair<GameProcessor::_dir, Entity*>(GameProcessor::L, delimLeft));
    walls.append(new QPair<GameProcessor::_dir, Entity*>(GameProcessor::T, delimUp));
    walls.append(new QPair<GameProcessor::_dir, Entity*>(GameProcessor::B, delimDown));
}

void GameProcessor::newGridVertical(char *name, FireBehavior *GridLineBehavior, int i)
{
    Entity *delimUp = EntityFactory::getEntity(name);
    delimUp->setBehavior(GridLineBehavior);
    this->scene.addItem(delimUp);
    delimUp->setScene(&(this->scene));
    delimUp->moveBy(i, -1 * WINSIZE_Y/2);
}

void GameProcessor::affGrid()
{
    FireBehavior *GridLineBehavior = new FireBehavior();
    GridLineBehavior->setRotationSpeed(0);

    /* Toutes les verticales */
    int i;
    i = -1 * WINSIZE_X/2;
    while(i < WINSIZE_X/2)
    {
        if (i != 0) //A SUPPRIMER sert à éviter le segfault des collisions
        newGridVertical((char *)"gridvert1", GridLineBehavior, i);
        i += 50;
    }
    i = -1 * WINSIZE_Y/2;
    while(i < WINSIZE_Y/2)
    {
        if (i != 0) //A SUPPRIMER sert à éviter le segfault des collisions
        newGridVertical((char *)"gridvert1", GridLineBehavior, i);
        i += 50;
    }

}
