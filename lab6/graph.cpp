#include "graph.h"

TGraph::TGraph(int n, TMatrix m)
{
    count = n;
    matrix = m;
}

TGraph::~TGraph()
{

}

void TGraph::setCount(int c)
{
    count = c;
}

void TGraph::setMatrix(TMatrix m)
{
    matrix = m;
}

int TGraph::getCount()
{
    return count;
}

TMatrix TGraph::getMatrix()
{
    return matrix;
}
