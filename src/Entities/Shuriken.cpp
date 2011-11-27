#include "Entities/Shuriken.h"
#include "Registry.h"
#include "SoundCenter.h"

Shuriken::Shuriken():Entity(){
  speed = 5;
    initPath();
    SoundCenter::get_instance()->play("shoot");
}

void Shuriken::initPath() {
      for (int i = 1; i < 5; ++i) {
          path.lineTo(-5 + 8 * cos(0.8 * i * PI), -5 + 8 * sin(0.8 * i * PI));
      }
      path.closeSubpath();
}

QRectF Shuriken::boundingRect() const {
    return this->path.boundingRect();
}

void Shuriken::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 ) {
    painter->setPen(QPen(QColor(79, 106, 25), 1, Qt::SolidLine,
                        Qt::FlatCap, Qt::MiterJoin));
    painter->setBrush(QColor(122, 163, 39));
    painter->drawPath(this->path);
}

Registry<Entity>::Add<Shuriken> shuriken("shuriken", "Shuriken shape entity");
