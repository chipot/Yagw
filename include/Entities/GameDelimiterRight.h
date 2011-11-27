#ifndef GAMEDELIMITERRIGHT_H
#define GAMEDELIMITERRIGHT_H

#include "Entity.h"

class GameDelimiterRight : public Entity
{

private:
    void initPath();

public:
    GameDelimiterRight();
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
};
#endif // GAMEDELIMITERRIGHT_H
