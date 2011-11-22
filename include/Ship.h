#ifndef SHIP_H
#define SHIP_H

#include "entity.h"

class Ship : public Entity
{

private :
    // private methods
    void initPath();
    int calcRotation();
    int fireLevel;

public :
    Ship();
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    void keyPressEvent( QKeyEvent * event );
    void keyReleaseEvent( QKeyEvent * keyEvent );
    void advance (int);
    void fire(QPointF direction);

};

#endif // SHIP_H
