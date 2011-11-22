#include "Ship.h"

Ship::Ship() {
    rotationSpeed = 4;
    initPath();
    fireLevel = 1;
}

void Ship::initPath() {
    path.lineTo(0, -11);
    path.lineTo(8.3, 0);
    path.lineTo(13.3, 3);
    path.lineTo(8.3, 6);
    path.lineTo(0, 17);
    path.closeSubpath();
}

QRectF Ship::boundingRect() const {
    return this->path.boundingRect();
}

void Ship::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 ) {
    painter->setPen(QColor("blue"));
    painter->drawPath(this->path);
}

int Ship::calcRotation() {
    int direction = directions[QPointF(move)];
    int rotate = - rotationSpeed;
    if ((direction - angle <= 180 && direction - angle > 0) || direction - angle <= -180)
        rotate = rotationSpeed;
    if (direction == angle)
        rotate = 0;
    angle += rotate;
    if (angle >= 360) {
        angle -= 360;
    }
    if (angle <= 0) {
        angle+= 360;
    }
    return rotate;
}

void Ship::advance(int phase) {
    if (phase == 1 && (move.x() != 0 || move.y() != 0)){
        this->setPos(pos() + move);
        this->rotate(calcRotation());
    }
}

void Ship::keyReleaseEvent( QKeyEvent * event ) {
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

void Ship::fire(QPointF direction) {


}

void Ship::keyPressEvent( QKeyEvent * event ) {
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
        case Qt::Key_Up :
           fire(QPointF(0, -1));
        case Qt::Key_Left :
            fire(QPointF(-1, 0));
        case Qt::Key_Down :
            fire(QPointF(0, 1));
        case Qt::Key_Right :
            fire(QPointF(1, 0));
        default :
            break;
    }
}

