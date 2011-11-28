#ifndef GREENSQUARE_H
#define GREENSQUARE_H


#include "Entity.h"

class Pacman : public Entity
{


private :
    // private methods
    void initPath();

public :
    Pacman();
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    virtual ~Pacman();
};

#endif // GREENSQUARE_H
