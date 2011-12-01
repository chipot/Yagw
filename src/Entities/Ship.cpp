#include "SoundCenter.h"
#include "Entities/Ship.h"
#include "Registry.h"

Ship::Ship() {
    speed = 3;
    initPath();
    this->_boundindrect = path.boundingRect();
}

void Ship::initPath() {
    path.lineTo(0, -11);
    path.lineTo(8.3, 0);
    path.lineTo(13.3, 3);
    path.lineTo(8.3, 6);
    path.lineTo(0, 17);
    path.closeSubpath();
}

void Ship::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 ) {
    painter->setPen(QColor("blue"));
    painter->drawPath(this->path);
}

Ship::~Ship()
{

}



Registry<Entity>::Add<Ship> ship("ship", "7:wired Ship shape entity");
