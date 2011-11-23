#ifndef YAGWSCENE_H
#define YAGWSCENE_H

// include lib

#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QGraphicsScene>
#include <QQueue>
#include <QRectF>
#include <QGraphicsItem>

// include shapes

#include "Ship.h"

// include behaviors

#include "PlayerBehavior.h"



class YagwScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit YagwScene(QObject *parent = 0);
private:
    void keyPressEvent( QKeyEvent * keyEvent );
    void keyReleaseEvent( QKeyEvent * keyEvent );
signals:
public slots:
    void drawBackground(QPainter *painter, const QRectF &rect);

private:
    Entity            *ship;
    QList<Entity*>   entities;
};

#endif // YAGWSCENE_H
