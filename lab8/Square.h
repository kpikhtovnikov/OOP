#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.h"
#include "Rhombus.h"

class Square : public Rectangle, public Rhombus
{
public:
    Square (const double &a);
};

#endif // SQUARE_H
