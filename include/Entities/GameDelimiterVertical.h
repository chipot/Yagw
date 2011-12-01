#ifndef GAMEDELIMITERVERTICAL_H
#define GAMEDELIMITERVERTICAL_H

#include "Entity.h"

class GameDelimiterVertical : public Entity
{

private:
    void initPath();

public:
    GameDelimiterVertical();
    virtual ~GameDelimiterVertical(){};
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
};

#endif // GAMEDELIMITERVERTICAL_H
