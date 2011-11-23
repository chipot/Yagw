#include "Ship.h"
#include "Registry.h"

Ship::Ship() {
    initPath();
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

Registry<Entity>::Add<Ship> ship("ship", "Ship shape entity");
