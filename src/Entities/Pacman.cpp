#include "SoundCenter.h"
#include "Entities/Pacman.h"
#include "Registry.h"

static const float Pi = 3.14159f;

Pacman::Pacman() {
    speed = 1;
    initPath();
}

void Pacman::initPath() {
  //this->setTransformOriginPoint(50.0, 50.0);
  path.moveTo(50.0, 50.0);
  path.arcTo(20.0, 30.0, 60.0, 40.0, 30.0, 270.0);
  path.closeSubpath();
}

void Pacman::paint(QPainter *painter, 
                        QStyleOptionGraphicsItem const * option, 
                        QWidget *widget = 0)
{
    painter->setPen(QColor("red"));
    painter->drawPath(this->path);
}

Pacman::~Pacman()
{
  SoundCenter::get_instance()->play("kill");
}

Registry<Entity>::Add<Pacman>
Pacman("pacman", "Pacman shape entity");
