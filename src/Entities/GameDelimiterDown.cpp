#include "Entities/GameDelimiterDown.h"
#include "Registry.h"

GameDelimiterDown::GameDelimiterDown() {
    initPath();
}


void GameDelimiterDown::initPath() {
    path.moveTo(-100, -100);
    path.addRect(-300, -300, 300, 300);
}

QRectF GameDelimiterDown::boundingRect() const {
    return this->path.boundingRect();
}

void GameDelimiterDown::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) {
    QPen pen(QColor("red"));
    pen.setWidth(3);
    painter->setPen(pen);
    painter->drawPath(this->path);
}

Registry<Entity>::Add<GameDelimiterDown> gameDelimiterDown("gamedelimiterdown", "GameDelimiterDown shape entity");
