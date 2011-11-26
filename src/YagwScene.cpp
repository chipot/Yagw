#include <QGraphicsWidget>
#include <QGraphicsScene>
#include "YagwScene.h"

YagwScene::YagwScene(QObject *parent) :
    QGraphicsScene(parent) {
    qDebug() << "instance scene";
    this->setSceneRect(-200,-200,1200,800);
}

void YagwScene::keyReleaseEvent(QKeyEvent *event) {
    emit forwardKeyReleaseEvent(event);
}

void YagwScene::keyPressEvent(QKeyEvent *event) {
    emit forwardKeyPressEvent(event);
}

void YagwScene::drawBackground(QPainter *painter, const QRectF &rect) {
    this->setSceneRect(-200,-200,1200,800);
    this->setBackgroundBrush(Qt::black);
}
