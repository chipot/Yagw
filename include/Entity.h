#ifndef ENTITY_H
#define ENTITY_H

#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QPointF>
#include <QDebug>
#include <QPainterPath>
#include <QGLWidget>

class Entity : public QGraphicsItem
{
public:
    Entity();
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    virtual void advance (int);

protected :
    QPainterPath path;
    QHash<QPointF, int> directions;
    QPointF move;
    int angle;
    int rotationSpeed;

private :

    void initDirections();


};

uint qHash(QPointF const &ptr);

#endif // ENTITY_H
