#include "Entities/GridVert1.h"
#include "Registry.h"

GridVert1::GridVert1() {
    initPath();
}

void GridVert1::initPath() {
    path.lineTo(0, 1000);
    path.closeSubpath();
}

QRectF GridVert1::boundingRect() const {
    return this->path.boundingRect();
}

void GridVert1::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) {
    QPen pen(QColor(255, 0, 0));
    pen.setWidthF(0.1);
    painter->setPen(pen);
    painter->drawPath(this->path);
}

Registry<Entity>::Add<GridVert1> gridVert1("gridvert1", "GridVert1 shape entity");

