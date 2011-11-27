#include "Entities/GridHor1.h"
#include "Registry.h"

GridHor1::GridHor1() {
    initPath();
}

void GridHor1::initPath() {
    path.lineTo(0, 1000);
    path.closeSubpath();
}

QRectF GridHor1::boundingRect() const {
    return this->path.boundingRect();
}

void GridHor1::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) {
    QPen pen(QColor(255, 0, 0));
    pen.setWidthF(0.1);
    painter->setPen(pen);
    painter->drawPath(this->path);
}

Registry<Entity>::Add<GridHor1> gridHor1("gridhor1", "GridHor1 shape entity");

