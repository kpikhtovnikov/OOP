#include "Parallelogram.h"

Parallelogram::Parallelogram (const double &a, const double &b, const double &alpha)
    : Quadrangle (a, b, a, alpha, 180 - alpha)
{

}
