#include "rational.h"
#include<math.h>

Rational::Rational()
{

}

Rational::Rational(const int& numerator)
{
    this->numerator = numerator;
    this->denominator = 1;
}

Rational Rational::operator+ (const Rational& rational)
{
    Rational p;
    int value_NOK = NOK(rational);
    int a = value_NOK/denominator, b = value_NOK/rational.denominator;
    p.numerator = numerator*a + rational.numerator*b;
    p.denominator = value_NOK;
    p.decrease();
    return p;
}

Rational Rational::operator* (const Rational& rational)
{
    Rational p;
    p.numerator = numerator*rational.numerator;
    p.denominator = denominator*rational.denominator;
    p.decrease();
    return p;
}

Rational Rational:: operator* (const int& value){
    Rational p;
    p.numerator = numerator*value;
    p.denominator = denominator;
    p.decrease();
    return p;
}

Rational Rational::operator/ (const Rational& rational){
    Rational p;

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

bool Rational::operator > (int value){
    return this->numerator > value*(int)this->denominator;
}

bool Rational::operator < (int value){
    return this->numerator < value*(int)this->denominator;
}

bool Rational::operator == (int value){
    return this->numerator == value*(int)this->denominator;
}

bool Rational::operator == (Rational rational)
{
    rational.decrease();
    return (denominator==rational.denominator && numerator==rational.numerator);
}

Rational Rational::operator- (const Rational& rational)
{
    Rational p;
    int value_NOK = NOK(rational);
    int a = value_NOK/denominator;
    int b = value_NOK/rational.denominator;
    p.numerator = numerator*a - rational.numerator*b;
    p.denominator = value_NOK;
    p.decrease();
    return p;
}

Rational Rational::operator- (){
    Rational p;
    p.numerator = -numerator;
    p.denominator = denominator;
    return p;
}

unsigned int Rational::NOK(const Rational& rational)
{
    return (rational.denominator*denominator)/NOD(rational.denominator,denominator);
}

void Rational::decrease()
{
    int value_NOD = NOD(numerator,denominator);
    numerator = numerator/value_NOD;
    denominator = denominator/value_NOD;
}

int Rational::NOD(const int& a1,const int& b1)
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

Rational sqrt(Rational rational){
    Rational newValue;
    newValue.numerator = sqrt(rational.numerator);
    newValue.denominator = sqrt(rational.denominator);
    newValue.decrease();
    return newValue;
}

ostream& operator << (ostream& os,const Rational& rational)
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

istream& operator >> (istream& is,Rational& rational)
{
    is>>rational.numerator>>rational.denominator;
    return is;
}
