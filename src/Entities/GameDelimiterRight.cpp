#include "Entities/GameDelimiterRight.h"
#include "Registry.h"

GameDelimiterRight::GameDelimiterRight() {
    initPath();
}

void GameDelimiterRight::initPath() {
//    path.moveTo(-100, -100);
//    path.addRect(-300, -300, 300, 300);
}

QRectF GameDelimiterRight::boundingRect() const {
    return this->path.boundingRect();
}

void GameDelimiterRight::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) {
    QPen pen(QColor("red"));
    pen.setWidth(3);
    painter->setPen(pen);
    painter->drawPath(this->path);
}

Registry<Entity>::Add<GameDelimiterRight> gameDelimiterRight("gamedelimiterright", "GameDelimiterRight shape entity");
