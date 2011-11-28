#include "Entity.h"
#include "Behavior.h"
#include "Score.h"

Entity::Entity(Profile *_profile) : profile(_profile), score(0), QGraphicsItem(), speed(100), move(QPointF(0,0)), rotationSpeed(0) {
    behavior = NULL;
    parentScene = NULL;
    spawnTime = new QTime();
    spawnTime->start();
    spawnShield = true;
    time.start();
}

Entity::Entity(YagwScene *scene) : QGraphicsItem() {
    move = QPointF(0,0);
    behavior = NULL;
    parentScene = scene;
    spawnTime = new QTime();
    spawnTime->start();
    spawnShield = true;
    speed = 100;
    time.start();
}

Entity::~Entity()
{
  Score::get_instance()->inc(this->score);
  delete behavior;
}

QRectF Entity::boundingRect() const {
    return this->path.boundingRect();
}

void Entity::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 ) {
    painter->drawRect(0,0,10,10);
}

QPointF Entity::calcMove() {
    float dist = speed * (float)(time.elapsed()/1000.0);
    QVector2D vector(move);
    vector.normalize();
    time.restart();
    return (QPointF(vector.x(), vector.y())* dist);
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

void Entity::setMove(QPointF move) {
    this->move = move;
}

const QPointF &Entity::getMove() const {
    return move;
}

int Entity::getRotationSpeed() const {
    return rotationSpeed;
}

void Entity::setRotationSpeed(int speed) {
    rotationSpeed = speed;
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

void Entity::setProfile(Profile *_profile) {
    this->profile = _profile;
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
