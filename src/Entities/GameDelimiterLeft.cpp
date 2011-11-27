#include "Entities/GameDelimiterLeft.h"
#include "Registry.h"

GameDelimiterLeft::GameDelimiterLeft() {
    initPath();
}


void GameDelimiterLeft::initPath() {
    path.moveTo(-100, -100);
    path.lineTo(-100, 100);
}

QRectF GameDelimiterLeft::boundingRect() const {
    return this->path.boundingRect();
}

void GameDelimiterLeft::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) {
    QPen pen(QColor("red"));
    pen.setWidth(3);
    painter->setPen(pen);
    painter->drawPath(this->path);
}

Registry<Entity>::Add<GameDelimiterLeft> gameDelimiterLeft("gamedelimiterleft", "GameDelimiterLeft shape entity");
