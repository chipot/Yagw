#include "Shuriken.h"

Shuriken::Shuriken() {
    initPath();
}

void Shuriken::initPath() {
      for (int i = 1; i < 5; ++i) {
          path.lineTo(50 + 40 * cos(0.8 * i * PI), 50 + 40 * sin(0.8 * i * PI));
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
