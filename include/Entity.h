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
#include <math.h>

#define PI 3.14f

class Behavior;
class YagwScene;

class Entity : public QGraphicsItem
{
private :
    Behavior *behavior;

public:
    Entity();
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
    void setBehavior(Behavior *behavior);

protected :
    QPainterPath path;
    YagwScene *parentScene;
    QPointF move;
    int rotation;
};


#endif // ENTITY_H
