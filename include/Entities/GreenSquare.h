#ifndef GREENSQUARE_H
#define GREENSQUARE_H


#include "Entity.h"

class GreenSquare : public Entity
{
private :
    // private methods
    void initPath();

public :
    GreenSquare();
//    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    virtual ~GreenSquare();
};

#endif // GREENSQUARE_H
