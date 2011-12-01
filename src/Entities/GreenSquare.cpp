#include "SoundCenter.h"
#include "Entities/GreenSquare.h"
#include "Registry.h"

GreenSquare::GreenSquare() {
    speed = 100;
    initPath();
    score = 20;
    this->_boundindrect = path.boundingRect();
}

void GreenSquare::initPath() {
    path.addRect(0, 0, 10, 10);
}

void GreenSquare::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 ) {
    QPen pen(QColor("green"));
    pen.setWidth(2);
    painter->setPen(pen);
    painter->drawPath(this->path);
}

GreenSquare::~GreenSquare()
{
  SoundCenter::get_instance()->play("kill");
}

Registry<Entity>::Add<GreenSquare> greenSquare("greensquare", "0:GreenSquare shape entity");
