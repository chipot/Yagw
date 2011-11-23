#include "GameProcessor.h"

GameProcessor::GameProcessor(YagwScene &ygws)
    : scene(ygws) {
    playerBehavior = new PlayerBehavior();
    QObject::connect(&scene, SIGNAL(forwardKeyPressEvent(QKeyEvent*)), playerBehavior, SLOT(keyPressEvent(QKeyEvent*)));
    QObject::connect(&scene, SIGNAL(forwardKeyReleaseEvent(QKeyEvent*)), playerBehavior, SLOT(keyReleaseEvent(QKeyEvent*)));
}


void GameProcessor::start(void) const {
}



