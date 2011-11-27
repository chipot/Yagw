#include "Entities/GameDelimiterUp.h"
#include "Registry.h"

GameDelimiterUp::GameDelimiterUp() {
    initPath();
}

void GameDelimiterUp::initPath() {
//    path.moveTo(-100, -100);
//    path.addRect(-300, -300, 300, 300);
}

QRectF GameDelimiterUp::boundingRect() const {
    return this->path.boundingRect();
}

void GameDelimiterUp::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) {
    QPen pen(QColor("red"));
    pen.setWidth(3);
    painter->setPen(pen);
    painter->drawPath(this->path);
}

Registry<Entity>::Add<GameDelimiterUp> gameDelimiterUp("gamedelimiterup", "GameDelimiterUp shape entity");
