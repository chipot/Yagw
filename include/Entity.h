#ifndef ENTITY_H
#define ENTITY_H

#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPointF>
#include <QDebug>
#include <QPainterPath>
#include <QGLWidget>
#include <QQueue>
#include <QVector2D>
#include <QTime>
#include <math.h>
#include "Profile.h"

#define PI 3.14159265f

class Behavior;
class YagwScene;

class Entity : public QGraphicsItem
{
protected :

    Behavior *behavior;
    Profile *profile;
    QPainterPath path;
    YagwScene *parentScene;
    QPointF move;
    QTime *spawnTime;
    bool spawnShield;
    int rotation;
    float speed;
    int score;
    int rotationSpeed;
    int lives;
    QTime time;

public:

    Entity(Profile *profile = 0);
    virtual ~Entity();
    Entity(YagwScene*);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    void advance (int);

    const QPointF &getMove() const;
    int getRotation() const;
    YagwScene *getScene() const;
    float getSpeed() const;
    int getRotationSpeed() const;

    void setMove(QPointF);
    void setRotation(int);
    void setScene(YagwScene*);
    void setBehavior(Behavior*);
    void setSpeed(float);
    void setProfile(Profile*);
    void setRotationSpeed(int speed);

    QPointF calcMove();
    int timeSinceSpawn() const;
    bool shielded();
    bool die();
    void setLives(const int);
};


#endif // ENTITY_H
