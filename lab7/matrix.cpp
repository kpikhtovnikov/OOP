#include "matrix.h"

TMatrix::TMatrix(unsigned int l,unsigned int c)
{
    lines = l;
    columns = c;
    data.resize(lines);
    for (size_t i = 0; i < lines; i++)
    {
        data[i].resize(columns);
    }
}

TMatrix::~TMatrix()
{
    for (size_t i = 0; i < data.size(); i++)
    {
        data[i].clear();
    }
    data.clear();
}

unsigned int TMatrix::get_lines()
{
    return lines;
}
unsigned int TMatrix::get_columns()
{
    return columns;
}

QVector < QVector<qint16> > TMatrix::get_data()
{
    return data;
}

void TMatrix::set_data(unsigned int l, unsigned int c, qint16 a)
{
    data[l][c]=a;
}
