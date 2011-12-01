#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QtCore/qmath.h>
#include <QVector2D>

class Calculator {
public :
    static QVector2D vectorialRotation(QVector2D vector, qreal angle) {
        QVector2D v(vector.x()*cos(angle*PI/180) - vector.y()*sin(angle*PI/180), vector.x()*sin(angle*PI/180) + vector.y()*cos(angle*PI/180));
        v.normalize();
        return v;
    }

    static QVector2D calcDirectionVector(QPointF firstPoint, QPointF secondPoint)
    {
        QVector2D vector(secondPoint.x() - firstPoint.x(), secondPoint.y() - firstPoint.y());
        vector.normalize();
        return (vector);
    }

    static qreal calcAngle(QVector2D u, QVector2D v) {

        qreal lower = u.length() * v.length();
        qreal dotprod = QVector2D::dotProduct(u, v);
        qreal alphacos = dotprod / lower + 0.0000001f;
        qreal alpharad = qAcos(alphacos);
        qreal alpha = alpharad * (180 / PI);

        return alpha;
    }
};

#endif // CALCULATOR_H
