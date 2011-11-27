#ifndef GAMEDELIMITERHORIZONTAL_H
#define GAMEDELIMITERHORIZONTAL_H

#include "Entity.h"

class GameDelimiterHorizontal : public Entity
{

private:
    void initPath();

public:
    GameDelimiterHorizontal();
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
};

#endif // GAMEDELIMITERHORIZONTAL_H
