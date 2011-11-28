#include "WallBehavior.h"

WallBehavior::WallBehavior(){
  rotationSpeed = 0;
  moveSpeed = 0;
  direction = QPointF(0,0);
}

inline void WallBehavior::behave(Entity *entity) {
  QPointF move = direction*moveSpeed;
  entity->setMove(move);
  entity->setRotation(rotationSpeed);
}

void WallBehavior::setDirection(QPointF dir) {
}

void WallBehavior::setRotationSpeed(int speed) {
}

