#ifndef GAMEDELIMITERUP_H
#define GAMEDELIMITERUP_H

#include "Entity.h"

class GameDelimiterUp : public Entity
{

private:
    void initPath();

public:
    GameDelimiterUp();
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
};
#endif // GAMEDELIMITERUP_H
