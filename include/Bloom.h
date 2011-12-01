#ifndef BLOOM_H
#define BLOOM_H

#include <QImage>
#include <QPainter>

class Bloom {
public:
    Bloom();
    QImage bloomed(const QImage&, int, int, int, QPainter::CompositionMode);
private:
    QImage enlight(const QImage&, const QRect&, int, int);
    QImage blurred(const QImage&, const QRect&, int);
    QImage brightened(const QImage&, int);
    QImage composited(const QImage&, const QImage&, int, QPainter::CompositionMode);
};

#endif // BLOOM_H
