#include "entity.h"

QRectF Entity::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

void Entity::paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 ) {
    painter->setPen(QColor("blue"));
    painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
}

void Entity::advance(int phase) {
    if (phase == 1)
        this->setPos(pos() + move);
}

void Entity::keyReleaseEvent( QKeyEvent * event ) {
//    move = QPointF(0,0);
}

void Entity::keyPressEvent( QKeyEvent * event ) {
    switch (event->key()) {
        case Qt::Key_W :
            move = QPointF(0, -1);
            break;
        case Qt::Key_A :
            move = QPointF(-1, 0);
            break;
        case Qt::Key_S :
            move = QPointF(0, 1);
            break;
        case Qt::Key_D :
            move = QPointF(1, 0);
        default :
            break;
    }
}
