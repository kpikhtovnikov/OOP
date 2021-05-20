#ifndef GRAPH_H
#define GRAPH_H

enum errors
{
    SUCCESS = 0,
    INVALID_NUM_OF_COLUMNS = 1,
    TOO_MANY_LINES,
    INVALID_ARGS,
};


#include <matrix.h>

class TGraph
{
protected:
    TMatrix *matrix;
    bool ready;
    unsigned int curr_str;


public:
    TGraph();
    ~TGraph();
    bool is_ready();
    int create_m(unsigned int,unsigned int);
    void delete_m();
    int add_m_line(QString);
    unsigned int get_m_lines();
    unsigned int get_m_columns();
    QVector < QVector<qint16> > get_matrix();
};

#endif // GRAPH_H
