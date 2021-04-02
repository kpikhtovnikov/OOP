#ifndef TPOLINOM_H
#define TPOLINOM_H
#include "number.h"
#include<iostream>
using namespace std;

enum EPrintMode{
    EPrintModeClassic,EPrintModeCanonic
};

class TPolinom
{
    EPrintMode printMode;
    number a,b,c;
    number Discriminant();
    bool RootsCheck(number*,int,number,number,number);
public:
    TPolinom();
    TPolinom(number,number,number);
    int QuantityOfRoots();
    friend ostream& operator << (ostream&, TPolinom&);
    number getValue(number);
    number getA();
    number getB();
    number getC();
    void setPrintMethod(EPrintMode);
    number *Roots();

    friend QString& operator << (QString&, TPolinom&);
};

#endif // TPOLINOM_H
