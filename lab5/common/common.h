#ifndef COMMON_H
#define COMMON_H

#include <QString>

enum messages
{
    VALUE_REQUEST = 1,
    VALUE_ANSWER,
    PRINT_CLASSIC_REQUEST,
    PRINT_CANONIC_REQUEST,
    PRINT_ANSWER,
    ROOTS,
    ROOTS_ANSWER
};

enum modes{
    INTEGER_MODE = 1,
    RATIONAL_MODE,
};

extern const QChar separator;
QString& operator<< (QString&,const QString&);

#endif // COMMON_H
