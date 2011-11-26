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
protected :

    Behavior *behavior;

    QPainterPath path;
    YagwScene *parentScene;
    QPointF move;
    int rotation;
    QPointF playerPosition;
    bool playerPositionUpdated;
    int speed;
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
    void setBehavior(Behavior*);
    void setPlayerPosition(QPointF);
    QPointF getPlayerPosition() const;
    bool playerMoved();
};


#endif // ENTITY_H
