#include "tpolinom.h"
#include "number.h"
#include<iostream>
#include<math.h>
using namespace std;

TPolinom::TPolinom(number A,number B,number C)
{
    printMode = EPrintModeClassic;
    a = A;
    b = B;
    c = C;
}
number TPolinom::getA(){
    return a;
}
number TPolinom::getB(){
    return b;
}
number TPolinom::getC(){
    return c;
}
void TPolinom::setPrintMethod(EPrintMode ePrintMethod)
{
    printMode = ePrintMethod;
}

number TPolinom::getValue(number x){
    return a*x*x+b*x+c;
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
    return b*b - a*c*4;
}


number* TPolinom::Roots(){
    number * ArrayOfRoots;
    if(QuantityOfRoots()==2){
        ArrayOfRoots = new number[2];
        ArrayOfRoots[0] = ((-b) + sqrt(Discriminant()))/(a*2);
        ArrayOfRoots[1] = ((-b) - sqrt(Discriminant()))/(a*2);
    }else if(QuantityOfRoots()==1){
        ArrayOfRoots = new number[1];
        ArrayOfRoots[0] = -b/(a*2);
    }else{
        ArrayOfRoots = NULL;
    }
    if(RootsCheck(ArrayOfRoots,QuantityOfRoots(),getA(),getB(),getC())){
        return ArrayOfRoots;
    }
    else{
        return NULL;
    }
    delete [] ArrayOfRoots;
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
     else{
        if (p.b == 0)
        {
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
        }

    }

    number*ArrayOfRoots = p.Roots();
    if(p.printMode == EPrintModeCanonic){
        if(p.QuantityOfRoots()==2){
            if (ArrayOfRoots[0]>0 && ArrayOfRoots[1]>0){
            os<<p.a<<"*"<<"(x-"<<ArrayOfRoots[0]<<")"<<"*"<<"(x-"<<ArrayOfRoots[1]<<")";
            }
            else if(ArrayOfRoots[0]<0 && ArrayOfRoots[1]<0){
             os<<p.a<<"*"<<"(x+"<<-ArrayOfRoots[0]<<")"<<"*"<<"(x+"<<-ArrayOfRoots[1]<<")";
            }
            else if(ArrayOfRoots[0]<0 && ArrayOfRoots[1]>0){
             os<<p.a<<"*"<<"(x+"<<-ArrayOfRoots[0]<<")"<<"*"<<"(x-"<<ArrayOfRoots[1]<<")";
            }
            else if(ArrayOfRoots[0]>0 && ArrayOfRoots[1]<0){
             os<<p.a<<"*"<<"(x-"<<ArrayOfRoots[0]<<")"<<"*"<<"(x+"<<-ArrayOfRoots[1]<<")";
            }
            else if(ArrayOfRoots[0]==0 && ArrayOfRoots[1]<0){
             os<<p.a<<"*"<<"x"<<"*"<<"(x+"<<-ArrayOfRoots[1]<<")";
            }
            else if(ArrayOfRoots[0]==0 && ArrayOfRoots[1]>0){
             os<<p.a<<"*"<<"x"<<"*"<<"(x-"<<ArrayOfRoots[1]<<")";
            }
            else if(ArrayOfRoots[0]>0 && ArrayOfRoots[1]==0){
             os<<p.a<<"*"<<"(x-"<<ArrayOfRoots[0]<<")"<<"*"<<"x";
            }
            else if(ArrayOfRoots[0]<0 && ArrayOfRoots[1]==0){
             os<<p.a<<"*"<<"(x+"<<-ArrayOfRoots[0]<<")"<<"*"<<"x";
            }
        }else if(p.QuantityOfRoots()==1){
              if (ArrayOfRoots[0]>0){
              os<<p.a<<"*"<<"(x-"<<ArrayOfRoots[0]<<")"<<"^2";
              }
              if (ArrayOfRoots[0]<0){
              os<<p.a<<"*"<<"(x+"<<-ArrayOfRoots[0]<<")"<<"^2";
              }
              if (ArrayOfRoots[0]==0){
              os<< p.a<<"x^2";
              }
        }else{
            os<<"The polynomial has no roots, so it is impossible to derive in canonical form";
        }
    }
    return os;
    delete [] ArrayOfRoots;
}

bool TPolinom:: RootsCheck(number*ArrayOfRoots,int quantityOfRoots,number a,number b,number c){
    if(quantityOfRoots==2){
        return (ArrayOfRoots[0]+ArrayOfRoots[1])==-(b/a) && ArrayOfRoots[0]*ArrayOfRoots[1]==(c/a) ;
    }else if(quantityOfRoots==1){
        return (ArrayOfRoots[0]+ArrayOfRoots[0])==-(b/a) && ArrayOfRoots[0]*ArrayOfRoots[0]==(c/a) ;
    }else{
        return false;
    }
}


QString& operator << (QString& os, TPolinom& p){
    if(p.printMode==EPrintModeClassic){
           os<<p.a;
           os+="x^2";
           if(p.b>0){
               os+="+";
               os<<p.b;
               os+="x";
           }else if(p.b<0){
               os<<p.b;
               os+="x";
           }
           if(p.c>0){
               os+="+";
               os<<p.c;
           }else if(p.c<0){
               os<<p.c;
           }
    }
    number*arrayOfRoots = p.Roots();
    if(p.printMode == EPrintModeCanonic){
        if(arrayOfRoots!=NULL){
        if(p.QuantityOfRoots()==2){
            if (arrayOfRoots[0]>0 && arrayOfRoots[1]>0){
            os<<p.a;
            os+="*";
            os+="(x-";
            os<<arrayOfRoots[0];
            os+=")";
            os+="*";
            os+="(x-";
            os<<arrayOfRoots[1];
            os+=")";
            }
            else if(arrayOfRoots[0]<0 && arrayOfRoots[1]<0){
             os<<p.a;
             os+="*";
             os+="(x+";
             os<<-arrayOfRoots[0];
             os+=")";
             os+="*";
             os+="(x+";
             os<<-arrayOfRoots[1];
             os+=")";
            }
            else if(arrayOfRoots[0]<0 && arrayOfRoots[1]>0){
             os<<p.a;
             os+="*";
             os+="(x+";
             os<<-arrayOfRoots[0];
             os+=")";
             os+="*";
             os+="(x-";
             os<<arrayOfRoots[1];
             os+=")";
            }
            else if(arrayOfRoots[0]>0 && arrayOfRoots[1]<0){
             os<<p.a;
             os+="*";
             os+="(x-";
             os<<arrayOfRoots[0];
             os=os+")"+"*"+"(x+";
             os<<-arrayOfRoots[1];
             os+=")";
            }
            else if(arrayOfRoots[0]==0 && arrayOfRoots[1]<0){
             os<<p.a;
             os=os+"*"+"x"+"*"+"(x+";
             os<<-arrayOfRoots[1];
             os+=")";
            }
            else if(arrayOfRoots[0]==0 && arrayOfRoots[1]>0){
             os<<p.a;
             os=os+"*"+"x"+"*"+"(x-";
             os<<arrayOfRoots[1];
             os+=")";
            }
            else if(arrayOfRoots[0]>0 && arrayOfRoots[1]==0){
             os<<p.a;
             os=os+"*"+"(x-";
             os<<arrayOfRoots[0];
             os=os+")"+"*"+"x";
            }
            else if(arrayOfRoots[0]<0 && arrayOfRoots[1]==0){
             os<<p.a;
             os=os+"*"+"(x+";
             os<<-arrayOfRoots[0];
             os=os+")"+"*"+"x";
            }
        }else if(p.QuantityOfRoots()==1){
              if (arrayOfRoots[0]>0){
              os<<p.a;
              os=os+"*"+"(x-";
              os<<arrayOfRoots[0];
              os=os+")"+"^2";
              }
              if (arrayOfRoots[0]<0){
              os<<p.a;
              os=os+"*"+"(x+";
              os<<-arrayOfRoots[0];
              os=os+")"+"^2";
              }
              if (arrayOfRoots[0]==0){
              os<< p.a;
              os+="x^2";
              }
        }
        }else{
            os+="The polynomial has no roots, so it is impossible to derive in canonical form";
        }
    }
    delete [] arrayOfRoots;
    return os;
}


