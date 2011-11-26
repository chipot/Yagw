#include "entity.h"
#include "Behavior.h"

Entity::Entity() : QGraphicsItem(), speed(1) {
    move = QPointF(0,0);
    behavior = NULL;
    parentScene = NULL;
    playerPositionUpdated = false;
}

Entity::Entity(YagwScene *scene) : QGraphicsItem() {
    move = QPointF(0,0);
    behavior = NULL;
    parentScene = scene;
}


QRectF Entity::boundingRect() const {
    return this->path.boundingRect();
}

// QRectF Entity::boundingRect() const {
//     return QRectF(0,0, 10, 10);
// }

void Entity::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 ) {
    painter->drawRect(0,0,10,10);
}

void Entity::advance (int phase) {
  if (phase == 0)
    for (int i  = 0; i < this->speed; ++i)
      {
        behavior->behave(this);
        playerPositionUpdated = false;
      }
  if (phase == 1) {
    this->setPos(pos() + move);
        this->rotate(rotation);
  }
}

YagwScene *Entity::getScene() const {
    return parentScene;
}

void Entity::setScene(YagwScene *scene) {
    this->parentScene = scene;
}

void Entity::setBehavior(Behavior *behavior) {
    if (this->behavior != NULL) {
        delete this->behavior;
    }
    this->behavior = behavior;
}

void Entity::setMove(QPointF &move) {
    this->move = move;
}

const QPointF &Entity::getMove() const {
    return move;
}

void Entity::setRotation(int rotate) {
    rotation = rotate;
}

int Entity::getRotation() const {
    return rotation;
}

void Entity::setPlayerPosition(QPointF position) {
    playerPosition = position;
    playerPositionUpdated = true;
}

QPointF Entity::getPlayerPosition() const {
    return playerPosition;
}

bool Entity::playerMoved() {
    return playerPositionUpdated;
}
