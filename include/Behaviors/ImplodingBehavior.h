#ifndef LGROWINGBEHAVIOR_H
#define LGROWINGBEHAVIOR_H

#include <QTimer>
#include "Behaviors.h"

class ImplodingBehavior : public QObject, public TransformationBehavior
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
    ImplodingBehavior(int duration = 2000, float ratio = 0.1) : TransformationBehavior(), growingDuration(duration) ,growingUp(true), actualSize(1), maxSize(ratio) {
        scale = (maxSize-actualSize) / (growingDuration / 60);
        timer.connect(&timer, SIGNAL(timeout()), this, SLOT(changeSize()));
    }
    virtual ~ImplodingBehavior() {
        timer.disconnect();
    }
    void transform();
    ImplodingBehavior *copy() const;

public slots:
    void changeSize();
private :
    void start();
};

#endif // GROWINGBEHAVIOR_H
