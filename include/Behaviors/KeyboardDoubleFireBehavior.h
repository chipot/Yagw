#ifndef KEYBOARDDOUBLEFIREBEHAVIOR_H
#define KEYBOARDDOUBLEFIREBEHAVIOR_H

#include "KeyboardFireBehavior.h"

class KeyboardDoubleFireBehavior : public KeyboardFireBehavior
{
Q_OBJECT
public :
    KeyboardDoubleFireBehavior(int fireFrequency = 150) : KeyboardFireBehavior(fireFrequency) {}
    virtual ~KeyboardDoubleFireBehavior(){}
    void fire();
};

#endif // KEYBOARDDOUBLEFIREBEHAVIOR_H
