#ifndef BASICROTATIONBEHAVIOR_H
#define BASICROTATIONBEHAVIOR_H

#include "Behaviors.h"

class BasicRotationBehavior : public RotationBehavior
{
protected:
    int rotationSpeed;
public :
    BasicRotationBehavior(Entity *ent = 0, int speed = 5) : RotationBehavior(ent), rotationSpeed(speed) {}
    void rotate();
    BasicRotationBehavior *copy();
};

#endif // BASICROTATIONBEHAVIOR_H
