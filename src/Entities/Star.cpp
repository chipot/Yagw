#include "SoundCenter.h"
#include "Entities/Star.h"
#include "Registry.h"

static const float Pi = 3.14159f;

Star::Star() {
    speed = 1;
    initPath();
}

void Star::initPath() {
  path.moveTo(90, 50);
  for (int i = 1; i < 5; ++i) {
    path.lineTo(50 + 40 * cos(0.8 * i * Pi),
                    50 + 40 * sin(0.8 * i * Pi));
  }
  path.closeSubpath();
  score = 12;
}

void Star::paint(QPainter *painter,
                        QStyleOptionGraphicsItem const * option,
                        QWidget *widget = 0)
{
    painter->setPen(QColor("yellow"));
    painter->drawPath(this->path);
}

Star::~Star()
{
  SoundCenter::get_instance()->play("kill");
}

Registry<Entity>::Add<Star>
Star("star", "5:Star shape entity");
