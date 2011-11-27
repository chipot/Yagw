#include "SoundCenter.h"
#include "Entities/GreenSquare.h"
#include "Registry.h"

GreenSquare::GreenSquare() {
    speed = 2;
    initPath();
    score = 20;
}

void GreenSquare::initPath() {
    path.addRect(0, 0, 10, 10);
}

void GreenSquare::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 ) {
    painter->setPen(QColor("green"));
    painter->drawPath(this->path);
}

GreenSquare::~GreenSquare()
{
  SoundCenter::get_instance()->play("kill");
}
Registry<Entity>::Add<GreenSquare> greenSquare("greensquare", "GreenSquare shape entity");
