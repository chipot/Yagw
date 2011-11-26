#include "GameProcessor.h"
#include "Registry.h"
#include "EntityFactory.h"

GameProcessor::GameProcessor(YagwScene &ygws)
    : scene(ygws) {
    qDebug() << "instance gameProcessor";

    QObject::connect(&scene, SIGNAL(newEntity(Entity*)), this, SLOT(loadEntity(Entity*)));

    playerBehavior = new PlayerBehavior();
    QObject::connect(playerBehavior, SIGNAL(phase0()), this, SLOT(checkCollidings()));
    QObject::connect(playerBehavior, SIGNAL(playerMoved()), this, SLOT(updatePlayerPosition()));
    QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)), playerBehavior, SLOT(keyPressEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyReleaseEvent(QKeyEvent*)), playerBehavior, SLOT(keyReleaseEvent(QKeyEvent*)));

    player = EntityFactory::getEntity("ship");
    if (player != NULL) {
        player->setBehavior(playerBehavior);
        scene.addItem(player);
        player->setScene(&scene);
    }
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
    qDebug() << "position" << random.x() << "|" <<  random.y();
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

void GameProcessor::spawnEnnemy1() {
    SimpleFollowingBehavior *behavior = new SimpleFollowingBehavior();
    QPointF entityPosition = randomPosition();
    Entity *entity = EntityFactory::getEntity("greensquare");
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

void GameProcessor::checkCollidings() {

    QList<QGraphicsItem*> collidingItems = player->collidingItems();

    QList<QGraphicsItem*>::iterator it = collidingItems.begin();
    QList<QGraphicsItem*>::iterator ite = collidingItems.end();

    for (;it != ite; ++it) {
        scene.removeItem((*it));
        delete (*it);
    }
}

