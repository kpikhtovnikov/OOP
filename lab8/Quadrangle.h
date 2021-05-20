#ifndef QUADRANGLE_H
#define QUADRANGLE_H
#include "Polygon.h"

class Quadrangle : public Polygon
{
public:
    explicit Quadrangle (const double &a, const double &b, const double &c,
                         const double &alpha, const double &beta);
};

#endif // QUADRANGLE_H
