#ifndef POLYGON_H
#define POLYGON_H

#include <QPainter>

class Polygon
{
    int quantityOfAngles;
public:
    Polygon(int);
    ~Polygon() = default;
    void draw(QPainter*,QRect,QColor);
};


#endif
