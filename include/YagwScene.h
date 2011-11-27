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
// include behaviors

class Entity;

class YagwScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit YagwScene(QObject *parent = 0);
private:
    void keyPressEvent( QKeyEvent * keyEvent );
    void keyReleaseEvent( QKeyEvent * keyEvent );
signals:
   void forwardKeyPressEvent(QKeyEvent*);
   void forwardKeyReleaseEvent(QKeyEvent*);
   void newEntity(Entity*);
   void newFire(Entity*);
public slots:
    void drawBackground(QPainter *painter, const QRectF &rect);

    friend class PlayerBehavior;
};

#endif // YAGWSCENE_H
