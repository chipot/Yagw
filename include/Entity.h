#ifndef ENTITY_H
#define ENTITY_H
#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QPointF>
#include <QDebug>

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
    QPointF move;

};

#endif // ENTITY_H
