#include "Entities/Shuriken.h"
#include "Registry.h"

Shuriken::Shuriken():Entity(){
    speed = 5;
    initPath();
    this->_boundindrect = path.boundingRect();
    this->_pen = QPen(QColor(79, 106, 25), 1, Qt::SolidLine,
                      Qt::FlatCap, Qt::MiterJoin);
    this->_brush = QBrush(QColor(122, 163, 39));
}

void Shuriken::initPath() {
      for (int i = 1; i < 5; ++i) {
          path.lineTo(-5 + 8 * cos(0.8 * i * PI), -5 + 8 * sin(0.8 * i * PI));
      }
      path.closeSubpath();
      score = 13;
}
/*
QRectF Shuriken::boundingRect() const {
    return this->_boundingrect;
}
*/

void Shuriken::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 ) {
    painter->setPen(this->_pen);
    painter->setBrush(this->_brush);
    painter->drawPath(this->path);
}

Registry<Entity>::Add<Shuriken> shuriken("shuriken", "3:Shuriken shape entity");
