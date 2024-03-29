#include "SoundCenter.h"
#include "Entities/Star.h"
#include "Registry.h"

static const float Pi = 3.14159f;

Star::Star() {
    speed = 1;
    initPath();
    this->_boundindrect = path.boundingRect();
    this->_pen = QPen(QColor("White"));

}

void Star::initPath() {
  path.moveTo(90, 50);
  for (int i = 1; i < 5; ++i) {
    path.lineTo(50 + 40 * cos(0.8 * i * Pi),
                    50 + 40 * sin(0.8 * i * Pi));
  }
  path.closeSubpath();
  score = 100;
}

void Star::paint(QPainter *painter,
                        QStyleOptionGraphicsItem const * option,
                        QWidget *widget = 0)
{
    painter->setPen(this->_pen);
    painter->drawPath(this->path);
}

Star::~Star()
{
  SoundCenter::get_instance()->play("kill");
}

Registry<Entity>::Add<Star>
Star("star", "5:Star shape entity");
