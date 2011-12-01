#include "Behaviors/KeyboardDoubleFireBehavior.h"
#include "Calculator.h"
#include "SoundCenter.h"



void KeyboardDoubleFireBehavior::fire() {
    using namespace std;
    Entity *fire1 = createFire(fireDirection);
    Entity *fire2 = createFire(fireDirection);
    fire1->setType(Entity::bullet);
    fire2->setType(Entity::bullet);
    QRectF brect = this->entity->boundingRect();
    qreal s = max(brect.height(), brect.width());
    s *= 1.2;
    int angle = 7;
    QVector2D d1 = Calculator::vectorialRotation(QVector2D(fireDirection), -angle);
    QVector2D d2 = Calculator::vectorialRotation(QVector2D(fireDirection), angle);
    fire1->moveBy(entity->pos().x() + d1.x()*s, entity->pos().y()+d1.y()*s);
    fire2->moveBy(entity->pos().x() + d2.x()*s, entity->pos().y()+d2.y()*s);
    SoundCenter::get_instance()->play("shoot");
}

