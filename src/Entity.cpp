#include "Entity.h"
#include "Behavior.h"
#include "Score.h"

Entity::Entity()
:score(0), QGraphicsItem(), speed(1), lives(1) {
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

void Entity::setLives(const int l)
{
  lives = l;
}

Entity::~Entity()
{
  Score::get_instance()->inc(this->score);
  delete behavior;
}

bool    Entity::die()
{
  --lives;
  return lives == 0;
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
    qDebug() << "advance";
  if (phase == 0)
      qDebug() << "try behave";
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
