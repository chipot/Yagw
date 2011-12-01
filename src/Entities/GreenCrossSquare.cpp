#include "SoundCenter.h"
#include "Entities/GreenCrossSquare.h"
#include "Registry.h"

GreenCrossSquare::GreenCrossSquare() {
    speed = 2;
    initPath();
    this->_boundindrect = path.boundingRect();
    score = 40;
    this->_pen = QPen(QColor("magenta"));
    _pen.setWidth(1);
}

void GreenCrossSquare::initPath() {
    path.addRect(0, 0, 10, 10);
    path.moveTo(10, 10);
    path.lineTo(0, 0);
    path.moveTo(0, 10);
    path.lineTo(10, 0);
    path.closeSubpath();
}

void GreenCrossSquare::paint(QPainter *painter,
                        QStyleOptionGraphicsItem const * option,
                        QWidget *widget = 0)
{
    painter->setPen(this->_pen);
    painter->drawPath(this->path);
}

GreenCrossSquare::~GreenCrossSquare()
{
  SoundCenter::get_instance()->play("kill");
}

Registry<Entity>::Add<GreenCrossSquare>
greenCrossSquare("greencrosssquare", "1: GreenCrossSquare shape entity");
