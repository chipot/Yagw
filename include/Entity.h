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
#include <math.h>

#define PI 3.14159265f

class Behavior;
class YagwScene;

class Entity : public QGraphicsItem
{
protected :

    Behavior *behavior;
    QPainterPath path;
    YagwScene *parentScene;
    QPointF move;
    int rotation;
    float speed;
    int score;

public:

    Entity();
    virtual ~Entity();
    Entity(YagwScene*);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    void advance (int);
    const QPointF &getMove() const;
    void setMove(QPointF&);
    int getRotation() const;
    void setRotation(int);
    void setScene(YagwScene*);
    YagwScene *getScene() const;
    void setBehavior(Behavior*);
    QPointF calcMove();
    float getSpeed() const;
    void setSpeed(float);
};


#endif // ENTITY_H
