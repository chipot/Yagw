#include "SoundCenter.h"
#include "Entities/GreenCrossSquare.h"
#include "Registry.h"

GreenCrossSquare::GreenCrossSquare() {
    speed = 2;
    initPath();
    score = 22;
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
    QPen pen(QColor("magenta"));
    pen.setWidth(2);
    painter->setPen(pen);
    painter->drawPath(this->path);
}

GreenCrossSquare::~GreenCrossSquare()
{
  SoundCenter::get_instance()->play("kill");
}

Registry<Entity>::Add<GreenCrossSquare>
greenCrossSquare("greencrosssquare", "1: GreenCrossSquare shape entity");
