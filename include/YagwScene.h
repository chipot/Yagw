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
#include <QList>
#include <QGraphicsView>

// include shapes
// include behaviors

class Entity;

class YagwScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit YagwScene(QObject *parent = 0);
    void translateViews(QPointF);
private:
    void keyPressEvent( QKeyEvent * keyEvent );
    void keyReleaseEvent( QKeyEvent * keyEvent );
    QGraphicsSimpleTextItem * score;
signals:
   void forwardKeyPressEvent(QKeyEvent*);
   void forwardKeyReleaseEvent(QKeyEvent*);
   void newEntity(Entity*);
   void newFire(Entity*);
   void phase2();
public slots:
    void advance();

   friend class PlayerBehavior;
};

#endif // YAGWSCENE_H
