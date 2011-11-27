#include "Entity.h"
#include "Behavior.h"

Entity::Entity() : QGraphicsItem(), speed(1) {
    move = QPointF(0,0);
    behavior = NULL;
    parentScene = NULL;
    spawnTime = new QTime();
    spawnTime->start();
    spawnShield = true;
}

Entity::Entity(YagwScene *scene) : QGraphicsItem() {
    move = QPointF(0,0);
    behavior = NULL;
    parentScene = scene;
}

Entity::~Entity()
{
    delete behavior;
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

QPointF Entity::calcMove() {
    QVector2D vector(move);
    vector.normalize();
    return (QPointF(vector.x(), vector.y())* speed);
}


void Entity::advance (int phase) {
  if (phase == 0)
        behavior->behave(this);
  if (phase == 1) {
    this->setPos(pos() + this->calcMove());
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

void Entity::setSpeed(float moveSpeed) {
    speed = moveSpeed;
}

float Entity::getSpeed() const {
    return speed;
}

bool Entity::shielded() {
    qDebug() << "shield ?";
    qDebug() << spawnShield;
    if (spawnShield == false)
        return false;
    if (spawnTime->elapsed() >= 2000) {
        spawnShield = false;
        delete spawnTime;
        spawnTime = 0;
        return false;
    }
    return true;
}
