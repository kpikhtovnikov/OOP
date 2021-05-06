#include "matrix.h"

TMatrix::TMatrix()
{
    x = 0; y =0;
}

TMatrix::TMatrix(int a, int b,QVector<QVector<qint16>> m)
{
 x =a; y = b; Matrix = m;
}

TMatrix::TMatrix(const TMatrix& m)
{
    x =m.x; y = m.y; Matrix = m.Matrix;
}

TMatrix::~TMatrix()
{

}

QVector<QVector<qint16>> TMatrix::Get()
{
    return this->Matrix;
}

bool TMatrix::Is_Adjacency_Matrix()
{
    bool flag = true;
    if (x != y)
        flag = false;
    else
    {
        for(int i = 0;i < x;i ++)
        {
            for(int j = 0;j < y; j++)
            {
                if(this->Matrix[i][j] != 0 && this->Matrix[i][j] != 1 && this->Matrix[i][i] != 0)
                    flag = false;
            }
        }
    }
    return flag;
}
