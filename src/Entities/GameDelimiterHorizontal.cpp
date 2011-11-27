
#include "Entities/GameDelimiterHorizontal.h"
#include "Registry.h"

GameDelimiterHorizontal::GameDelimiterHorizontal() {
    initPath();
}

void GameDelimiterHorizontal::initPath() {
    path.lineTo(1000, 0);
    path.closeSubpath();
}

QRectF GameDelimiterHorizontal::boundingRect() const {
    return this->path.boundingRect();
}

void GameDelimiterHorizontal::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) {
    QPen pen(QColor("red"));
    pen.setWidth(3);
    painter->setPen(pen);
    painter->drawPath(this->path);
}

Registry<Entity>::Add<GameDelimiterHorizontal> gameDelimiterHorizontal("gamedelimiterhorizontal", "GameDelimiterHorizontal shape entity");
