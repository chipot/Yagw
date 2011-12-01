#include "Entity.h"
#include "Behavior.h"
#include "Score.h"

Entity::Entity(Profile *_profile, const char *name) :
    QGraphicsItem(), profile(_profile),
    parentScene(0), move(QPointF(0,0)), spawnTime(new QTime()),
    spawnShield(true), rotation(0), speed(100), score(0),
    rotationSpeed(0), lives(1), time(QTime()),  orientation(90),
    index(QString(name)), type(Entity::unknow)
{
    spawnTime->start();
    time.start();
}


Entity::Entity(YagwScene *scene) : QGraphicsItem() {
    move = QPointF(0,0);
    parentScene = scene;
    spawnTime = new QTime();
    spawnTime->start();
    spawnShield = true;
    speed = 100;
    time.start();
}

void Entity::setLives(const int l)
{
  lives = l;
}

Entity::~Entity()
{
  Score::get_instance()->inc(this->score);
  delete profile;
  delete spawnTime;
}

bool    Entity::die()
{
  --lives;
  return lives == 0;
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
    if (profile) {
        if (phase == 0)
            profile->process();
        if (phase == 1) {
            this->setPos(pos() + move);
            this->rotate(rotation);
        }
    }
}

YagwScene *Entity::getScene() const {
    return parentScene;
}

void Entity::setScene(YagwScene *scene) {
    this->parentScene = scene;
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
  this->profile->setEntity(this);
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

int Entity::getOrientation() const {
    return orientation;
}


void Entity::setIndex(const char *name) {
    index = QString(name);
}
