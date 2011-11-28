#ifndef GREENSQUARE_H
#define GREENSQUARE_H


#include "Entity.h"

class GreenCrossSquare : public Entity
{


private :
    // private methods
    void initPath();

public :
    GreenCrossSquare();
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    virtual ~GreenCrossSquare();
};

#endif // GREENSQUARE_H
