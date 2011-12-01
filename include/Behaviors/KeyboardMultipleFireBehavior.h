#ifndef KEYBOARDMULTIPLEFIREBEHAVIOR_H
#define KEYBOARDMULTIPLEFIREBEHAVIOR_H

#include "Behaviors/KeyboardFireBehavior.h"

class KeyboardMultipleFireBehavior : public KeyboardFireBehavior
{
    Q_OBJECT

private :
    int number;
    qreal spacing;

public :
    KeyboardMultipleFireBehavior(int fireFrequency = 150, int n = 2, int angle = 7) : KeyboardFireBehavior(fireFrequency), number(n), spacing(angle) {}
    virtual ~KeyboardMultipleFireBehavior(){}
    void fire();
};

#endif // KEYBOARDMULTIPLEFIREBEHAVIOR_H
