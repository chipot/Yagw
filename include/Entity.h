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
#include <math.h>

#define PI 3.14

class Behavior;
class YagwScene;

class Entity : public QGraphicsItem
{
public:
    Entity();
    Entity(YagwScene*);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    virtual void advance (int);
    const QPointF &getMove() const;
    void setMove(QPointF&);
    int getRotation() const;
    void setRotation(int);
    void setScene(YagwScene*);
    YagwScene *getScene() const;
    void setBehavior(Behavior *behavior);
//    bool sceneEvent(QEvent *);
    void keyPressEvent( QKeyEvent * event );
    void keyReleaseEvent( QKeyEvent * event );

protected :
    QPainterPath path;
    YagwScene *parentScene;
    QPointF move;
    int rotation;

private :

    Behavior *behavior;
};


#endif // ENTITY_H
