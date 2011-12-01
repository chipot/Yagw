#include "Entities/Fire01.h"
#include "Registry.h"

Fire01::Fire01() {
    speed = 300;
    initPath();
    this->_boundindrect = this->path.boundingRect();
    this->_pen = QPen(QColor("yellow"));
    this->_brush = QBrush(QColor("yellow"));
}

Fire01::~Fire01()
{
}

void Fire01::initPath() {
    path.addEllipse(-4, -4, 4, 4);
    path.closeSubpath();
}

void Fire01::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) {    
    painter->setPen(this->_pen);
    painter->setBrush(this->_brush);
    painter->drawPath(this->path);
}

Registry<Entity>::Add<Fire01> fire01("fire01", "Fire01 shape entity");
