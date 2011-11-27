#include "Entities/GameDelimiterVertical.h"
#include "Registry.h"

GameDelimiterVertical::GameDelimiterVertical() {
    initPath();
}

void GameDelimiterVertical::initPath() {
    path.lineTo(0, 1000);
    path.closeSubpath();
}

QRectF GameDelimiterVertical::boundingRect() const {
    return this->path.boundingRect();
}

void GameDelimiterVertical::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) {
    QPen pen(QColor("red"));
    pen.setWidth(3);
    painter->setPen(pen);
    painter->drawPath(this->path);
}

Registry<Entity>::Add<GameDelimiterVertical> gameDelimiterVertical("gamedelimitervertical", "GameDelimiterVertical shape entity");

