#ifndef GAMEDELIMITERDOWN_H
#define GAMEDELIMITERDOWN_H

#include "Entity.h"

class GameDelimiterDown : public Entity
{

private:
    void initPath();

public:
    GameDelimiterDown();
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
};
#endif // GAMEDELIMITERDOWN_H
