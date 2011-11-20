#include "yagwscene.h"

YagwScene::YagwScene(QObject *parent) :
    QGraphicsScene(parent) {
    ship = new Entity();
    ship->setAcceptTouchEvents(true);
    this->addItem(this->ship);
    this->setSceneRect(-100,-100,200,200);
}

void YagwScene::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_W :
        case Qt::Key_A :
        case Qt::Key_S :
        case Qt::Key_D :
        case Qt::Key_Left :
        case Qt::Key_Up :
        case Qt::Key_Right :
        case Qt::Key_Down :
            this->sendEvent(ship, event);
        default :
            break;
    }
}

void YagwScene::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_W :
        case Qt::Key_A :
        case Qt::Key_S :
        case Qt::Key_D :
            this->sendEvent(ship, event);
        case Qt::Key_Left :
        case Qt::Key_Up :
        case Qt::Key_Right :
        case Qt::Key_Down :
            // gestion des tirs
        default :
            break;
    }

}

void YagwScene::drawBackground(QPainter *painter, const QRectF &rect) {
    this->setSceneRect(-100,-100,200,200);
}
