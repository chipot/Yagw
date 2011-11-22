#include "entity.h"
#include <QGLWidget>

Entity::Entity() : QGraphicsItem() {
    move = QPointF(0,0);
}

QRectF Entity::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

void Entity::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 ) {
    painter->setPen(QColor("blue"));
    painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
}

void Entity::advance(int phase) {
    if (phase == 1)
        this->setPos(pos() + move);
}

void Entity::keyReleaseEvent( QKeyEvent * event ) {
//    move = QPointF(0,0);
    switch (event->key()) {
        case Qt::Key_W :
            move.setY(0);
            break;
        case Qt::Key_A :
            move.setX(0);
            break;
        case Qt::Key_S :
            move.setY(0);
            break;
        case Qt::Key_D :
            move.setX(0);
        default :
            break;
    }
}

void Entity::keyPressEvent( QKeyEvent * event ) {
    switch (event->key()) {
        case Qt::Key_W :
            move.setY(-1);
            break;
        case Qt::Key_A :
            move.setX(-1);
            break;
        case Qt::Key_S :
            move.setY(1);
            break;
        case Qt::Key_D :
            move.setX(1);
        default :
            break;
    }
}
