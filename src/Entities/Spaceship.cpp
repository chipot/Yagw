#include "Entities/Spaceship.h"
#include "SoundCenter.h"
#include "Registry.h"

Spaceship::Spaceship() {
    speed = 200;
    initPath();
    this->_boundindrect = path.boundingRect();
}

void Spaceship::initPath() {

//    path.moveTo(20, 0);
//    path.lineTo(5, 10);
//    path.lineTo(-5, 25);
//    path.lineTo(-15, 5);
//    path.lineTo(-15, -5);
//    path.lineTo(-5, -25);
//    path.lineTo(5, -10);
//    path.lineTo(20, 0);

    path.moveTo(10, 0);
    path.lineTo(-10, 7);
    path.lineTo(-10, -7);
    path.lineTo(10, 0);
    path.closeSubpath();
}

QRectF Spaceship::boundingRect() const {
    return this->path.boundingRect();
}

void Spaceship::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) {
    QPen pen(QColor("red"));
    pen.setWidth(2);
    painter->setPen(pen);
    painter->drawPath(this->path);
}

Registry<Entity>::Add<Spaceship> spaceship("spaceship", "Spaceship shape entity");

Spaceship::~Spaceship()
{
  SoundCenter::get_instance()->play("quack");
}
