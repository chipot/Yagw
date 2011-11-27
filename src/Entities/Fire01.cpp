#include "Entities/Fire01.h"
#include "Registry.h"

Fire01::Fire01() {
    initPath();
}

void Fire01::initPath() {
    path.addEllipse(-4, -4, 4, 4);
    //path.closeSubpath();
}

QRectF Fire01::boundingRect() const {
    return this->path.boundingRect();
}

void Fire01::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) {
    painter->setPen(QColor("yellow"));
    painter->setBrush(QColor("yellow"));
    painter->drawPath(this->path);
}

Registry<Entity>::Add<Fire01> fire01("fire01", "Fire01 shape entity");
