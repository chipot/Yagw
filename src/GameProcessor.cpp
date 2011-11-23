#include "GameProcessor.h"
#include "Registry.h"

GameProcessor::GameProcessor(YagwScene &ygws)
    : scene(ygws) {
    playerBehavior = new PlayerBehavior();
    QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)), playerBehavior, SLOT(keyPressEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyReleaseEvent(QKeyEvent*)), playerBehavior, SLOT(keyReleaseEvent(QKeyEvent*)));

}

void GameProcessor::start(void) const {
    Registry<Entity>::iterator it = Registry<Entity>::begin();
    Registry<Entity>::iterator ite = Registry<Entity>::end();
    for (;it != ite; ++it) {
        Registry<Entity>::entry e = *it;
        qDebug() << e.getName();
        qDebug() << e.getDesc();
        Ship *s = static_cast<Ship*>(e.instantiate());
    }

}







