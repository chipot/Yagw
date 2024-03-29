#include <QGraphicsWidget>
#include <QGraphicsScene>
#include "YagwScene.h"
#include "EntityFactory.h"

YagwScene::YagwScene(QObject *parent) :
  QGraphicsScene(parent) {
  this->setSceneRect(-500,-500,1000,1000);
  this->setItemIndexMethod(NoIndex);
  setBackgroundImage();
}

void YagwScene::keyReleaseEvent(QKeyEvent *event) {
    emit forwardKeyReleaseEvent(event);
}

void YagwScene::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape)
      emit quit();
    emit forwardKeyPressEvent(event);
}

void YagwScene::advance() {
    QGraphicsScene::advance();
    emit phase2();
}

void YagwScene::createFire(Entity *fire) {
    fire->setScene(this);
    this->addItem(fire);
    emit this->newFire(fire);
}

void YagwScene::translateViews(QPointF coordinates) {
    QList<QGraphicsView*> views = this->views();
    QList<QGraphicsView*>::iterator it = views.begin();
    QList<QGraphicsView*>::iterator ite = views.end();

    for (; it != ite; ++it) {
        (*it)->translate(coordinates.x(), coordinates.y());
    }
}

void YagwScene::setBackgroundImage() {
//    QBrush backgroundColor(Qt::black, Qt::SolidPattern);
//    this->setBackgroundBrush(backgroundColor);

//    QRect backGround(-500,-500,1000,1000);


    QImage *img = new QImage("grid.png");
    if (img->isNull())
        qDebug() << "grid image can not be loaded";
    else {
        QRect rect();

        QBrush *brush = new QBrush(*img);
        brush->setTextureImage(*img);
        this->setBackgroundBrush(*brush);
    }
}
