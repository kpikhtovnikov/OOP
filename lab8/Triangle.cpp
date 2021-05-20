#include "Triangle.h"

Triangle::Triangle (const double &a, const double &b, const double &angle)
{
    _edge.append (a);
    _edge.append (b);
    _angle.append (angle);
    calcInternal ();
}

