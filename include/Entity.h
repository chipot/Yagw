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
    void keyPressEvent( QKeyEvent * event );
    void keyReleaseEvent( QKeyEvent * keyEvent );
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    void advance (int);
private :
    QPainterPath path;
    QPointF move;
    int angle;
    int direction;

};

#endif // ENTITY_H
