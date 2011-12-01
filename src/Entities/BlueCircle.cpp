#include "SoundCenter.h"
#include "Entities/BlueCircle.h"
#include "Registry.h"

BlueCircle::BlueCircle() {
    speed = 0;
    initPath();
    this->_boundindrect = path.boundingRect();
    this->_pen = QPen(QColor("Blue"));
    this->_pen.setWidth(1);
    this->lives = 10;
}

void BlueCircle::initPath() {
    path.addEllipse(0, 0, 15, 15);
    path.closeSubpath();
    score = 60;

}

void BlueCircle::paint(QPainter *painter,
                        QStyleOptionGraphicsItem const * option,
                        QWidget *widget = 0)
{
    painter->setPen(this->_pen);
    painter->drawPath(this->path);
}

BlueCircle::~BlueCircle()
{
  SoundCenter::get_instance()->play("kill");
}

Registry<Entity>::Add<BlueCircle>
Circle("bluecircle", "4:blue circle shape entity");

