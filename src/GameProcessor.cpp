#include "GameProcessor.h"
#include "Registry.h"
#include "EntityFactory.h"

GameProcessor::GameProcessor(YagwScene &ygws)
    : scene(ygws) {
    qDebug() << "instance gameProcessor";
    playerBehavior = new PlayerBehavior();
    QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)), playerBehavior, SLOT(keyPressEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyReleaseEvent(QKeyEvent*)), playerBehavior, SLOT(keyReleaseEvent(QKeyEvent*)));
    player = EntityFactory::getEntity("ship");
    if (player != NULL) {
        player->setBehavior(playerBehavior);
        scene.addItem(player);
    }
}

void GameProcessor::setPlayer(const char *name) {
    if (player != NULL) {
        scene.removeItem(player);
    }
    player = EntityFactory::getEntity(name);
    if (player != NULL) {
        player->setBehavior(playerBehavior);
        scene.addItem(player);
    }
}

void GameProcessor::start(void) {
    qDebug() << "start";
}







