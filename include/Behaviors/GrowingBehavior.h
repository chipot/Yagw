#ifndef GROWINGBEHAVIOR_H
#define GROWINGBEHAVIOR_H

#include <QTimer>
#include "Behaviors.h"

class GrowingBehavior : public QObject, public TransformationBehavior
{
Q_OBJECT

private:
    int growingDuration;
    bool growingUp;
    float actualSize;
    float maxSize;
    float scale;
    QTimer timer;

public :
    GrowingBehavior(int duration = 2000, float ratio = 2) : TransformationBehavior(), growingDuration(duration) ,growingUp(true), actualSize(1), maxSize(ratio) {
        scale = (maxSize-actualSize) / (growingDuration / 60);
        timer.connect(&timer, SIGNAL(timeout()), this, SLOT(changeSize()));
    }
    virtual ~GrowingBehavior() {
        timer.disconnect();
    }
    void transform();
    GrowingBehavior *copy();

public slots:
    void changeSize();
private :
    void start();
};

#endif // GROWINGBEHAVIOR_H
