#ifndef ENTITY_H
#define ENTITY_H

#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPointF>
#include <QDebug>
#include <QPainterPath>
#include <QGLWidget>
#include <QQueue>
#include <QVector2D>
#include <QTime>
#include <QTimer>
#include <QSharedPointer>
#include <math.h>
#include "Profile.h"

#define PI 3.14159265f

class YagwScene;

class Entity : public QObject, public QGraphicsItem
{
    Q_OBJECT

 public:
    enum kind
    {
      bullet,
      unknow
    };
 protected :
    Profile *profile;
    QPainterPath path;
    YagwScene *parentScene;
    QPointF move;
    QTime *spawnTime;
    bool spawnShield;
    int rotation;
    float speed;
    int score;
    int rotationSpeed;
    int lives;
    QTime time;
    int orientation;
    QString index;
    QRectF _boundindrect;
    kind type;
    QPen _pen;
    QBrush _brush;
  private:
    bool is_exploding;
    QTimer  *timer;

 public:
    Entity(Profile *profile = 0, const char* name="");
    Entity::kind getType() const {return this->type;}
    void setType(kind k){this->type = k;}
    virtual ~Entity();
    Entity(YagwScene*);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    void advance (int);
    void explode();
    const QPointF &getMove() const;
    int getRotation() const;
    YagwScene *getScene() const;
    float getSpeed() const;
    int getRotationSpeed() const;
    int getOrientation() const;
    QString getIndex() const;
    void setMove(QPointF);
    void setRotation(int);
    void setScene(YagwScene*);
    void setSpeed(float);
    void setProfile(Profile*);
    void setRotationSpeed(int speed);
    void setIndex(QString);

    QPointF calcMove();
    int timeSinceSpawn() const;
    bool shielded();
    bool die();
    void setLives(const int);
  public slots:
    void finishExplode();
 };

typedef QSharedPointer<Entity> EntityPtr;

#endif // ENTITY_H
