#include "SoundCenter.h"
#include "Entities/Pacman.h"
#include "Registry.h"

static const float Pi = 3.14159f;

Pacman::Pacman() {
    speed = 1;
    orientation = 270;
    initPath();
    score = 42;
}

void Pacman::initPath() {
  //this->setTransformOriginPoint(50.0, 50.0);
 // path.moveTo(50.0, 50.0);

  path.arcTo(QRectF(-30, -30, 60, 60), 30, 270);
  path.closeSubpath();
}

void Pacman::paint(QPainter *painter,
                        QStyleOptionGraphicsItem const * option,
                        QWidget *widget = 0)
{
    QPen pen(QColor("Yellow"));
    pen.setWidth(2);
    painter->setPen(pen);
    painter->drawPath(this->path);
}

Pacman::~Pacman()
{
  SoundCenter::get_instance()->play("kill");
}

Registry<Entity>::Add<Pacman>
Pacman("pacman", "2:Pacman shape entity");
