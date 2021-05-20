#ifndef MATRIX_H
#define MATRIX_H

#include <QVector>

class TMatrix
{
private:
    QVector < QVector<qint16> > data;
    unsigned int lines;
    unsigned int columns;
public:
    TMatrix(unsigned int,unsigned int);
    ~TMatrix();
    unsigned int get_lines();
    unsigned int get_columns();
    QVector < QVector<qint16> >  get_data();
    void set_data(unsigned int,unsigned int,qint16);
};

#endif // MATRIX_H
