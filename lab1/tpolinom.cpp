#include "tpolinom.h"
#include "number.h"
#include<iostream>
#include<math.h>
using namespace std;

TPolinom::TPolinom(number a,number b,number c)
{
    printMode = EPrintModeClassic;
    this->a = a;
    this->b = b;
    this->c = c;
}
number TPolinom::getA(){
    return this->a;
}
number TPolinom::getB(){
    return this->b;
}
number TPolinom::getC(){
    return this->c;
}
void TPolinom::setPrintMethod(EPrintMode ePrintMethod)
{
    this->printMode = ePrintMethod;
}

number TPolinom::getValue(number x){
    return this->a*x*x+this->b*x+this->c;
}

int TPolinom::QuantityOfRoots(){
    if(Discriminant()>0){
        return 2;
    }
    if(Discriminant()==0){
        return 1;
    }
    if(Discriminant()<0){
        return 0;
    }
    return -1;
}

number TPolinom::Discriminant(){
    return this->b*this->b - 4*this->a*this->c;
}


number* TPolinom::Roots(){
    number * roots;
    if(QuantityOfRoots()==2){
        roots = new int[2];
        roots[0] = (-b + sqrt(Discriminant()))/(2*a);
        roots[1] = (-b - sqrt(Discriminant()))/(2*a);
    }else if(QuantityOfRoots()==1){
        roots = new int[1];
         roots[0] = -b/(2*a);
    }else{
        roots = NULL;
    }
    return roots;
}


ostream& operator << (ostream& os, TPolinom& p){
    if(p.printMode==EPrintModeClassic){
        if ((p.a > 0) || (p.a < 0))
        {
                os<< p.a<<"x^2";
                if (p.b > 0)
                {
                    os << "+" << p.b <<"x";
                    if (p.c == 0)
                        os << "";
                    if (p.c > 0)
                        os<<"+"<< p.c<<"";
                    else if(p.c<0)
                        os << p.c << "";
                }
                if (p.b < 0)
                {
                    os << p.b << "x";
                    if (p.c == 0)
                        os << "";
                    if (p.c > 0)
                        os<<"+"<< p.c<<"";
                    else if(p.c<0)
                        os << p.c << "";
                }
                if (p.b == 0)
                {
                    if (p.c == 0)
                        os << " ";
                    if (p.c > 0)
                        os<<"+"<< p.c<<" ";
                    else if(p.c<0)
                        os << p.c << " ";
                }
        }

            if (p.b < 0)
            {
                os << p.b << "x";
                if (p.c == 0)
                    os << "";
                if (p.c > 0)
                    os<<"+"<< p.c<<"";
                else if(p.c<0)
                    os << p.c << "";
            }
            if (p.b == 0)
            {
                if (p.c == 0)
                    os << "";
                if (p.c > 0)
                    os<<"+"<< p.c<<"";
                else if(p.c<0)
                    os << p.c << "";
            }
    }

    number*roots = p.Roots();
    if(p.printMode == EPrintModeCanonic){
        if(p.QuantityOfRoots()==2){
            if (roots[0]>0 && roots[1]>0){
            os<<p.a<<"*"<<"(x-"<<roots[0]<<")"<<"*"<<"(x-"<<roots[1]<<")";
            }
            else if(roots[0]<0 && roots[1]<0){
             os<<p.a<<"*"<<"(x+"<<-roots[0]<<")"<<"*"<<"(x+"<<-roots[1]<<")";
            }
            else if(roots[0]<0 && roots[1]>0){
             os<<p.a<<"*"<<"(x+"<<-roots[0]<<")"<<"*"<<"(x-"<<roots[1]<<")";
            }
            else if(roots[0]>0 && roots[1]<0){
             os<<p.a<<"*"<<"(x-"<<roots[0]<<")"<<"*"<<"(x+"<<-roots[1]<<")";
            }
            else if(roots[0]==0 && roots[1]<0){
             os<<p.a<<"*"<<"x"<<"*"<<"(x+"<<-roots[1]<<")";
            }
            else if(roots[0]==0 && roots[1]>0){
             os<<p.a<<"*"<<"x"<<"*"<<"(x-"<<roots[1]<<")";
            }
            else if(roots[0]>0 && roots[1]==0){
             os<<p.a<<"*"<<"(x-"<<roots[0]<<")"<<"*"<<"x";
            }
            else if(roots[0]<0 && roots[1]==0){
             os<<p.a<<"*"<<"(x+"<<-roots[0]<<")"<<"*"<<"x";
            }
        }else if(p.QuantityOfRoots()==1){
              if (roots[0]>0){
              os<<p.a<<"*"<<"(x-"<<roots[0]<<")"<<"^2";
              }
              if (roots[0]<0){
              os<<p.a<<"*"<<"(x+"<<-roots[0]<<")"<<"^2";
              }
              if (roots[0]==0){
              os<< p.a<<"x^2";
              }
        }else{
            os<<"The polynomial has no roots, so it is impossible to derive in canonical form";
        }
    }
    return os;
    delete [] roots;
}




