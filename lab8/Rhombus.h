#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "Parallelogram.h"

class Rhombus : virtual public Parallelogram
{
public:
    Rhombus (const double &a, const double &alpha);
};

#endif // RHOMBUS_H
