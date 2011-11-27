#include "GameProcessor.h"
#include "Registry.h"
#include "EntityFactory.h"

GameProcessor::GameProcessor(YagwScene &ygws)
    : scene(ygws) {
    qDebug() << "instance gameProcessor";

    QObject::connect(&scene, SIGNAL(newEntity(Entity*)), this, SLOT(loadEntity(Entity*)));
    QObject::connect(&scene, SIGNAL(newFire(Entity*)), this, SLOT(loadFire(Entity*)));
    QObject::connect(&scene, SIGNAL(phase2()), this, SLOT(checkCollidings()));
    playerBehavior = new PlayerBehavior();
    QObject::connect(playerBehavior, SIGNAL(playerMoved()), this, SLOT(updatePlayerPosition()));
    QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)), playerBehavior, SLOT(keyPressEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyReleaseEvent(QKeyEvent*)), playerBehavior, SLOT(keyReleaseEvent(QKeyEvent*)));

    player = EntityFactory::getEntity("spaceship");
    if (player != NULL) {
        player->setBehavior(playerBehavior);
        scene.addItem(player);
        player->setScene(&scene);
    }

    playerLifes = 3;
}

void GameProcessor::setPlayer(const char *name) {
    if (player != NULL) {
        scene.removeItem(player);
    }
    delete player;
    player = EntityFactory::getEntity(name);
    if (player != NULL) {
        player->setBehavior(playerBehavior);
        scene.addItem(player);
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


void GameProcessor::start(void) {
    QTimer *ennemy1Timer = new QTimer();
    ennemy1Timer->connect(ennemy1Timer, SIGNAL(timeout()), this, SLOT(spawnEnnemy1()));
    ennemy1Timer->start(1000/3);

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
    qDebug() << "lol";
}

void GameProcessor::spawnEnnemy1() {
    SimpleFollowingBehavior *behavior = new SimpleFollowingBehavior();
    QPointF entityPosition = randomPosition();
    Entity *entity = EntityFactory::getEntity("greensquare");
    entity->setScene(&scene);
    entity->setBehavior(behavior);
    entity->setPlayerPosition(player->pos());
    spawnEntity(entity, entityPosition);
    entities << entity;
}

void GameProcessor::updatePlayerPosition() {

    QList<Entity*>::iterator it = entities.begin();
    QList<Entity*>::iterator ite = entities.end();

    for (;it != ite; ++it) {
        (*it)->setPlayerPosition(player->pos());
    }
}

void GameProcessor::playerDead() {
  QList<Entity*> to_delete;
  QGraphicsItem *item;

  to_delete << this->fire;
  to_delete << this->entities;
  foreach(item, to_delete)
    {
      scene.removeItem(item);
      //delete item;
    }
  this->fire.erase(this->fire.begin(), this->fire.end());
  this->entities.erase(this->entities.begin(), this->entities.end());
  // playerLifes--;
  // if (playerLifes == 0) {
  //   qDebug() << "YOU ARE DEAD";
  // }
}

void GameProcessor::checkCollidings()
{
    QList<QGraphicsItem*> to_delete;
    QList<QGraphicsItem*> used_fire;
    QGraphicsItem *item;
    int size = 0;

    // ATTENTION DEUX MUNITION QUI COLLIDE ENTRE ELLES = plantage
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
    if (this->player->collidingItems().size() != 0)
      this->playerDead();
}

