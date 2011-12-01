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
        start();
        scale = (maxSize-actualSize) / (growingDuration / 60);
        qDebug() << scale;
    }
    virtual ~GrowingBehavior() {
        timer.disconnect();
    }
    void transform();

public slots:
    void changeSize();
private :
    void start();
};

#endif // GROWINGBEHAVIOR_H
