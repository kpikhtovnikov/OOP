#ifndef TGRAPH_H
#define TGRAPH_H

#include <QObject>
#include "matrix.h"

class TGraph
{
    int count;
    TMatrix matrix;
public:
    TGraph(int, TMatrix);
    ~TGraph();
    int getCount();
    void setCount(int);
    TMatrix getMatrix();
    void setMatrix(TMatrix);
};

#endif // TGRAPH_H
