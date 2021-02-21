#ifndef TAPPLICATION_H
#define TAPPLICATION_H
#include "number.h"

class TApplication
{
bool RootsInteger(number*,int,number,number,number);
int menu();
public:
    TApplication();
    void exec();

};

#endif // TAPPLICATION_H
