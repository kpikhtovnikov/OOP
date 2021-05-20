#ifndef POLYGON_H
#define POLYGON_H
#include <math.h>
#include <iostream>
#include <QList>
#include <QString>
#define PI 3.14159265

using namespace std;

class Polygon
{
public:
    Polygon();
    Polygon(const QList<double> &edge, const QList<double> &angle);
    virtual ~Polygon();

    double area();
    double perimetr();

protected:
    void calcInternal();
    QList<double> _edge;
    QList<double> _angle;
    QList<double> _iEdge;
    QList<double> _iAngle;
};

#endif // POLYGON_H
