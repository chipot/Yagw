#include "GameProcessor.h"
#include "Registry.h"
#include "EntityFactory.h"
#include "Entity.h"

GameProcessor::GameProcessor(YagwScene &ygws)
  : scene(ygws), player(0), playerLifes(3) {
    qDebug() << "instance gameProcessor";

    QObject::connect(&scene, SIGNAL(newEntity(Entity*)), this, SLOT(loadEntity(Entity*)));
    QObject::connect(&scene, SIGNAL(newFire(Entity*)), this, SLOT(loadFire(Entity*)));
    QObject::connect(&scene, SIGNAL(phase2()), this, SLOT(checkCollidings()));
    playerBehavior = NULL;
    gameTimer = new QTimer();
    GameProcessor::affDelimiters();
    //GameProcessor::affGrid();
}

void GameProcessor::setPlayer()
{
    playerBehavior = new PlayerBehavior();
    QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)), playerBehavior, SLOT(keyPressEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyReleaseEvent(QKeyEvent*)), playerBehavior, SLOT(keyReleaseEvent(QKeyEvent*)));
    player = EntityFactory::getEntity("spaceship");
    if (player != NULL) {
        player->setBehavior(playerBehavior);
        scene.addItem(player);
        player->setScene(&scene);
        player->setFlag(QGraphicsItem::ItemIsFocusable, true);
        scene.setFocusItem(player);
    }
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
}

void GameProcessor::start(int framePerSecond)
{
    gameTimer->connect(gameTimer, SIGNAL(timeout()), &scene, SLOT(advance()));
    gameTimer->start(framePerSecond);

    this->setPlayer();

    ennemy1Timer = new QTimer();
    ennemy1Timer->connect(ennemy1Timer, SIGNAL(timeout()), this, SLOT(spawnEnnemy1()));
    ennemy1Timer->start(2000);
}

void GameProcessor::generateEntity(const char *name) {
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
    SimpleFollowingBehavior *behavior = new SimpleFollowingBehavior();
    QPointF entityPosition = randomPosition();
    Entity *entity = EntityFactory::getEntity("greensquare");
    entity->setScene(&scene);
    entity->setBehavior(behavior);
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

  playerLifes--;
  scene.removeItem(this->player);
  delete this->player;
  if (playerLifes != 0)
    this->setPlayer();
  else
    this->stop();
}

void GameProcessor::checkCollidings()
{
    QList<QGraphicsItem*> to_delete;
    QList<QGraphicsItem*> used_fire;
    QGraphicsItem *item;
    int size = 0;

    foreach(item, this->fire)
      {
        to_delete << item->collidingItems();
        if (size != to_delete.size())
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
        if (static_cast<Entity*>(item) == this->player)
          continue;
        scene.removeItem((item));
        this->entities.removeOne(static_cast<Entity*>(item));
        delete item;
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

void GameProcessor::affDelimiters() {
    FireBehavior *delimBehavior = new FireBehavior();
    delimBehavior->setRotationSpeed(0);

    Entity *delimDown = EntityFactory::getEntity("gamedelimiterhorizontal");
    delimDown->setBehavior(delimBehavior);
    this->scene.addItem(delimDown);
    delimDown->setScene(&(this->scene));
    delimDown->moveBy(-1 * WINSIZE_X/2, WINSIZE_Y/2);

    Entity *delimUp = EntityFactory::getEntity("gamedelimiterhorizontal");
    delimUp->setBehavior(delimBehavior);
    this->scene.addItem(delimUp);
    delimUp->setScene(&(this->scene));
    delimUp->moveBy(-1 * WINSIZE_X/2, -1 * WINSIZE_Y/2);

    Entity *delimLeft = EntityFactory::getEntity("gamedelimitervertical");
    delimLeft->setBehavior(delimBehavior);
    this->scene.addItem(delimLeft);
    delimLeft->setScene(&(this->scene));
    delimLeft->moveBy(-1 * WINSIZE_X/2, -1 * WINSIZE_Y/2);

    Entity *delimRight = EntityFactory::getEntity("gamedelimitervertical");
    delimRight->setBehavior(delimBehavior);
    this->scene.addItem(delimRight);
    delimRight->setScene(&(this->scene));
    delimRight->moveBy(WINSIZE_X/2, -1 * WINSIZE_Y/2);
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
