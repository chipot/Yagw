#ifndef FIRE01_H
#define FIRE01_H

#include "Entity.h"

class Fire01 : public Entity
{

private:
    void initPath();

public:
    Fire01();
    virtual ~Fire01();
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
};

#endif // FIRE01_H
