#ifndef YAGWSCENE_H
#define YAGWSCENE_H
#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QGraphicsScene>
#include <QQueue>
#include <QRectF>
#include <QGraphicsItem>
#include "entity.h"


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
    QQueue<int>	_keyq;
    Entity *ship;
};

#endif // YAGWSCENE_H
