#include "graph.h"
#include <QDebug>

TGraph::TGraph()
{
    matrix = nullptr;
    ready = false;
}

TGraph::~TGraph()
{
    if (matrix != nullptr) delete matrix;
}

bool TGraph::is_ready()
{
    return ready;
}

int TGraph::create_m(unsigned int l,unsigned int c)
{
    matrix = new TMatrix(l,c);
    curr_str = 0;
    ready = false;
    return 0;
}

void TGraph::delete_m()
{
    if (matrix != nullptr) delete matrix;
    ready = false;
}

int TGraph::add_m_line(QString inp)
{
    int tmp;
    if (ready)
    {
        qDebug() << "Ошибка: слишком много строк в файле";
        return TOO_MANY_LINES;
    }
    QStringList list = inp.split(" ");
    if (list.size()!=matrix->get_columns())
    {
        qDebug() << "Ошибка: неверное количество чисел в строке: " << list.size();
        return INVALID_NUM_OF_COLUMNS;
    }
    for (size_t i = 0; i < list.size(); i++)
    {
        tmp=list[i].toInt();
        if ((tmp < 0)||(tmp>=matrix->get_lines()))
        {
            qDebug() << "Ошибка: неправильные числа в матрице";
            return INVALID_ARGS;
        }
        else
        {
            matrix->set_data(curr_str,i,tmp);
        }
    }
    curr_str++;
    if (curr_str==matrix->get_lines()) ready = true;
    return SUCCESS;
}



unsigned int TGraph::get_m_lines()
{
    return matrix->get_lines();
}

unsigned int TGraph::get_m_columns()
{
    return matrix->get_columns();
}
QVector < QVector<qint16> > TGraph::get_matrix()
{
    return matrix->get_data();
}
