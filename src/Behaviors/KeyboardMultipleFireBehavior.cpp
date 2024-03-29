#include "Behaviors/KeyboardMultipleFireBehavior.h"
#include "Calculator.h"
#include "SoundCenter.h"


void KeyboardMultipleFireBehavior::fire() {
    using namespace std;
    QRectF brect = this->entity->boundingRect();
    qreal s = max(brect.height(), brect.width());
    s *= 1.2;
    qreal angle = 0;
    int middle = floor(number/2)+1;
    for (int i = 1; i <= number; i++) {
        if (number % 2 == 0) {
            if (i > number/2) {
                angle = spacing * (i - number/2);
            } else {
                angle = spacing * (i - (number/2+1));
            }
        } else {
            if (i == middle) {
                angle = 0;
            } else if (i < middle) {
                angle = spacing * (i - middle);
            } else {
                angle = spacing * (i - middle);
            }
        }
        QVector2D direction(Calculator::vectorialRotation(QVector2D(fireDirection), angle));
        Entity *fire = createFire(direction.toPointF());
        fire->setType(Entity::bullet);
        fire->moveBy(entity->pos().x() + direction.x()*s, entity->pos().y()+direction.y()*s);
    }
    SoundCenter::get_instance()->play("shoot");
}

void KeyboardMultipleFireBehavior::setNumber(int n) {
    number = n;
}
