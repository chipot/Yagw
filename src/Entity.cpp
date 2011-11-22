#include "entity.h"

uint qHash(QPointF const &ptr) {
    return (ptr.x() * 1000 + ptr.y());
}

Entity::Entity() : QGraphicsItem() {
    move = QPointF(0,0);
    angle = 90;
    rotationSpeed = 1;
    initDirections();
}

void Entity::initDirections() {
    directions[QPointF(0, 1)] = 180;
    directions[QPointF(1, 0)] = 90;
    directions[QPointF(1, 1)] = 135;
    directions[QPointF(0, -1)] = 360;
    directions[QPointF(1, -1)] = 45;
    directions[QPointF(-1, 0)] = 270;
    directions[QPointF(-1, -1)] = 315;
    directions[QPointF(-1, 1)] = 225;
}

QRectF Entity::boundingRect() const {
    return QRectF(0,0, 10, 10);
}

void Entity::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 ) {
    painter->drawRect(0,0,10,10);
}

void Entity::advance (int phase) {

}
