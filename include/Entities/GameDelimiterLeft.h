#ifndef GAMEDELIMITERLEFT_H
#define GAMEDELIMITERLEFT_H

#include "Entity.h"

class GameDelimiterLeft : public Entity
{

private:
    void initPath();

public:
    GameDelimiterLeft();
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
};
#endif // GAMEDELIMITERLEFT_H
