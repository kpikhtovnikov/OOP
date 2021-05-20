#include "Quadrangle.h"

Quadrangle::Quadrangle (const double &a, const double &b, const double &c,
                        const double &alpha, const double &beta)
{
    _edge.append (a);
    _edge.append (b);
    _edge.append (c);
    _angle.append (alpha);
    _angle.append (beta);
    calcInternal ();
}
