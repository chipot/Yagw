#include "entity.h"
#include "Behavior.h"

Entity::Entity() : QGraphicsItem() {
    move = QPointF(0,0);
    behavior = NULL;
    parentScene = NULL;
}

Entity::Entity(YagwScene *scene) : QGraphicsItem() {
    move = QPointF(0,0);
    behavior = NULL;
    parentScene = scene;
}


QRectF Entity::boundingRect() const {
    return QRectF(0,0, 10, 10);
}

void Entity::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 ) {
    painter->drawRect(0,0,10,10);
}

void Entity::advance (int phase) {
    if (phase == 0) {
        behavior->behave(this);
    }
    if (phase == 1) {
        this->setPos(pos() + move);
        this->rotate(rotation);
    }
}

YagwScene *Entity::getScene() const {
    return parentScene;
}

void Entity::setScene(YagwScene *scene) {
    this->parentScene = scene;
}

/*
bool Entity::sceneEvent(QEvent *event) {
    if (behavior != NULL) {
        behavior->sendEvent(event);
        qDebug() << event->isAccepted();
        return event->isAccepted();
    }
    return true;
}
*/


void Entity::keyPressEvent( QKeyEvent * event ) {
    behavior->keyPressEvent(event);
}

void Entity::keyReleaseEvent( QKeyEvent * event ) {
    behavior->keyReleaseEvent(event);
}

void Entity::setBehavior(Behavior *behavior) {
    if (this->behavior != NULL) {
        delete this->behavior;
    }
    this->behavior = behavior;
}

void Entity::setMove(QPointF &move) {
    this->move = move;
}

const QPointF &Entity::getMove() const {
    return move;
}

void Entity::setRotation(int rotate) {
    rotation = rotate;
}

int Entity::getRotation() const {
    return rotation;
}
