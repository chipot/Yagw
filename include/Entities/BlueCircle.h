#ifndef BLUECIRCLE_H
#define BLUECIRCLE_H

#include "Entity.h"

class BlueCircle : public Entity
{
private :
    // private methods
    void initPath();

public :
    BlueCircle();
//    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    virtual ~BlueCircle();
};

#endif // BLUECIRCLE_H
