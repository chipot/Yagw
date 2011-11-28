#ifndef GREENSQUARE_H
#define GREENSQUARE_H


#include "Entity.h"

class Star : public Entity
{


private :
    // private methods
    void initPath();

public :
    Star();
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    virtual ~Star();
};

#endif // GREENSQUARE_H
