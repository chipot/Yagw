#include <QGraphicsWidget>
#include <QGraphicsScene>
#include "YagwScene.h"

YagwScene::YagwScene(QObject *parent) :
    QGraphicsScene(parent) {
    qDebug() << "instance scene";
    this->setSceneRect(-200,-200,400,400);
    QBrush backgroundColor(Qt::black, Qt::SolidPattern);
    this->setBackgroundBrush(backgroundColor);
}

void YagwScene::keyReleaseEvent(QKeyEvent *event) {
    emit forwardKeyReleaseEvent(event);
}

void YagwScene::keyPressEvent(QKeyEvent *event) {
    emit forwardKeyPressEvent(event);
}


void YagwScene::advance() {
    QGraphicsScene::advance();
    emit phase2();
}