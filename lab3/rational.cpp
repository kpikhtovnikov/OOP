#include "rational.h"
#include<math.h>

TRational::TRational()
{

}

TRational::TRational(const int& numerator)
{
    this->numerator = numerator;
    this->denominator = 1;
}

TRational::TRational(const int& numerator,const int& denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}


TRational TRational::operator+ (const TRational& rational)
{
    TRational p;
    int value_NOK = NOK(rational);
    int a = value_NOK/denominator;
    int b = value_NOK/rational.denominator;
    p.numerator = numerator*a + rational.numerator*b;
    p.denominator = value_NOK;
    p.decrease();
    return p;
}

TRational TRational::operator* (const TRational& rational)
{
    TRational p;
    p.numerator = numerator*rational.numerator;
    p.denominator = denominator*rational.denominator;
    p.decrease();
    return p;
}

TRational TRational:: operator* (const int& value){
    TRational p;
    p.numerator = numerator*value;
    p.denominator = denominator;
    p.decrease();
    return p;
}

TRational TRational::operator/ (const TRational& rational){
    TRational p;

    if(rational.numerator<0){
        p.numerator = -rational.denominator*numerator;
        p.denominator = rational.numerator*denominator;
    }else{
        p.numerator = rational.denominator*numerator;
        p.denominator = rational.numerator*denominator;
    }
    p.decrease();
    return p;
}

bool TRational::operator > (int value){
    return this->numerator > value*(int)this->denominator;
}

bool TRational::operator < (int value){
    return this->numerator < value*(int)this->denominator;
}

bool TRational::operator == (int value){
    return this->numerator == value*(int)this->denominator;
}

bool TRational::operator == (TRational rational)
{
    rational.decrease();
    return (denominator==rational.denominator && numerator==rational.numerator);
}

TRational TRational::operator- (const TRational& rational)
{
    TRational p;
    int value_NOK = NOK(rational);
    int a = value_NOK/denominator;
    int b = value_NOK/rational.denominator;
    p.numerator = numerator*a - rational.numerator*b;
    p.denominator = value_NOK;
    p.decrease();
    return p;
}

TRational TRational::operator- (){
    TRational p;
    p.numerator = -numerator;
    p.denominator = denominator;
    return p;
}

unsigned int TRational::NOK(const TRational& rational)
{
    return (rational.denominator*denominator)/NOD(rational.denominator,denominator);
}

void TRational::decrease()
{
    int value_NOD = NOD(numerator,denominator);
    numerator = numerator/value_NOD;
    denominator = denominator/value_NOD;
}

int TRational::NOD(const int& a1,const int& b1)
{
    int a = abs(a1), b = abs(b1);
    while(a!=0 && b!=0){
        if (a>=b)
            a = a%b;
        else
            b = b%a;
    }
    return a+b;
}

/*TRational TRational::fraction(const double p){
    TRational newValue;
    double eps=0.0000000000000000000000001;      //точность
    double num=p;
    double denom=1.0/(eps*10.0);
    num = int(num*denom);
    double gcd = (double)NOD((int)num, (int)denom);
    num /= gcd;
    denom /= gcd;
    newValue.numerator=num;
    newValue.denominator=denom;
    return newValue;
}*/

TRational sqrt(TRational rational){
    TRational newValue;
    //TRational num,denom;
    //double newValue1,newValue2;
    //newValue1 = sqrt(rational.numerator);
   // newValue2 = sqrt(rational.denominator);
   // num=num.fraction(newValue1);
    //denom=denom.fraction(newValue2);
    //newValue=num/denom;
    newValue.numerator = sqrt(rational.numerator);
    newValue.denominator = sqrt(rational.denominator);
    newValue.decrease();
    return newValue;
}

ostream& operator << (ostream& os,const TRational& rational)
{
    if(rational.numerator>=0 && rational.numerator % rational.denominator == 0){
        os<<rational.numerator/(int)rational.denominator;
    }else if(rational.numerator<0 && (-rational.numerator) % rational.denominator == 0){
        os<<rational.numerator/(int)rational.denominator;
    }else{
        rational.numerator<0?
                    os<<"-"<<"("<<-rational.numerator<<"/"<<rational.denominator<<")":
                    os<<"("<<rational.numerator<<"/"<<rational.denominator<<")";
    }
    return os;
}

istream& operator >> (istream& is,TRational& rational)
{
    is>>rational.numerator>>rational.denominator;
    return is;
}

QString& operator <<(QString &s, const TRational& rational)
{
    if(rational.numerator>=0 && rational.numerator % rational.denominator == 0){
        s+=QString().setNum(rational.numerator/(int)rational.denominator);
    }else if(rational.numerator<0 && (-rational.numerator) % rational.denominator == 0){
        s+=QString().setNum(rational.numerator/(int)rational.denominator);
    }else{
        rational.numerator<0?
                    s=s+"-"+"("+QString().setNum(-rational.numerator)+"/"+QString().setNum(rational.denominator)+")":
                    s=s+"("+QString().setNum(rational.numerator)+"/"+QString().setNum(rational.denominator)+")";
    }

    return s;
}
