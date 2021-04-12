#ifndef TPOLINOM_H
#define TPOLINOM_H

#include <QString>
#include<iostream>
#include<math.h>
using namespace std;

enum EPrintMode{
    EPrintModeClassic,EPrintModeCanonic
};

template <class number>
class TPolinom
{
    EPrintMode printMode;
    number a,b,c;
    bool RootsCheck(number*,int);
    number Discriminant();
public:
    TPolinom();
    TPolinom(number,number,number);
    int QuantityOfRoots();

    template <class T>
    friend ostream& operator << (ostream&, TPolinom<T>&);
    number getValue(number);
    void setPrintMethod(EPrintMode);
    number *Roots();

    template <class T>
    friend QString& operator << (QString&, TPolinom<T>&);
};

template <class number>
TPolinom<number>::TPolinom(number A,number B,number C)
{
    printMode = EPrintModeClassic;
    a = A;
    b = B;
    c = C;
}

template <class number>
void TPolinom<number>::setPrintMethod(EPrintMode ePrintMethod)
{
    this->printMode = ePrintMethod;
}

template <class number>
number TPolinom<number>::getValue(number x){
    return a*x*x+b*x+c;
}

template <class number>
int TPolinom<number>::QuantityOfRoots(){
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

template <class number>
number TPolinom<number>::Discriminant(){
    return b*b - a*c*4;
}

template <class number>
number* TPolinom<number>::Roots(){
    number * roots;
    if(QuantityOfRoots()==2){
        roots = new number[2];
        roots[0] = ((-b) + sqrt(Discriminant()))/(a*2);
        roots[1] = ((-b) - sqrt(Discriminant()))/(a*2);
        if(!RootsCheck(roots,2)){
            roots = NULL;
        }
    }else if(QuantityOfRoots()==1){
        roots = new number[1];
         roots[0] = -b/(a*2);
         if(!RootsCheck(roots,1)){
             roots = NULL;
         }
    }else{
        roots = NULL;
    }
    return roots;
}

template <class number>
bool TPolinom<number>:: RootsCheck(number*roots,int quantityOfRoots){
    if(quantityOfRoots==2){
        return (roots[0]+roots[1])==-(b/a) && (roots[0]*roots[1])==(c/a) ;
    }else if(quantityOfRoots==1){
        return (roots[0]+roots[0])==-(b/a) && roots[0]*roots[0]==(c/a) ;
    }else{
        return false;
    }
}

template <class number>
ostream& operator << (ostream& os, TPolinom<number>& p){
    if(p.printMode==EPrintModeClassic){
           os<<p.a<<"x^2";
           if(p.b>0){
               os<<"+"<<p.b<<"x";
           }else if(p.b<0){
               os<<p.b<<"x";
           }
           if(p.c>0){
               os<<"+"<<p.c;
           }else if(p.c<0){
               os<<p.c;
           }
    }
    number*roots = p.Roots();
    if(p.printMode == EPrintModeCanonic){
        if(roots!=NULL){
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
        }
        }else{
            os<<"Канонический вид невозможен";
        }
    }
    delete [] roots;
    return os;
}

template <class number>
QString& operator << (QString& os, TPolinom<number>& p){
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
    number*roots = p.Roots();
    if(p.printMode == EPrintModeCanonic){
        if(roots!=NULL){
        if(p.QuantityOfRoots()==2){
            if (roots[0]>0 && roots[1]>0){
            os<<p.a;
            os+="*";
            os+="(x-";
            os<<roots[0];
            os+=")";
            os+="*";
            os+="(x-";
            os<<roots[1];
            os+=")";
            }
            else if(roots[0]<0 && roots[1]<0){
             os<<p.a;
             os+="*";
             os+="(x+";
             os<<-roots[0];
             os+=")";
             os+="*";
             os+="(x+";
             os<<-roots[1];
             os+=")";
            }
            else if(roots[0]<0 && roots[1]>0){
             os<<p.a;
             os+="*";
             os+="(x+";
             os<<-roots[0];
             os+=")";
             os+="*";
             os+="(x-";
             os<<roots[1];
             os+=")";
            }
            else if(roots[0]>0 && roots[1]<0){
             os<<p.a;
             os+="*";
             os+="(x-";
             os<<roots[0];
             os=os+")"+"*"+"(x+";
             os<<-roots[1];
             os+=")";
            }
            else if(roots[0]==0 && roots[1]<0){
             os<<p.a;
             os=os+"*"+"x"+"*"+"(x+";
             os<<-roots[1];
             os+=")";
            }
            else if(roots[0]==0 && roots[1]>0){
             os<<p.a;
             os=os+"*"+"x"+"*"+"(x-";
             os<<roots[1];
             os+=")";
            }
            else if(roots[0]>0 && roots[1]==0){
             os<<p.a;
             os=os+"*"+"(x-";
             os<<roots[0];
             os=os+")"+"*"+"x";
            }
            else if(roots[0]<0 && roots[1]==0){
             os<<p.a;
             os=os+"*"+"(x+";
             os<<-roots[0];
             os=os+")"+"*"+"x";
            }
        }else if(p.QuantityOfRoots()==1){
              if (roots[0]>0){
              os<<p.a;
              os=os+"*"+"(x-";
              os<<roots[0];
              os=os+")"+"^2";
              }
              if (roots[0]<0){
              os<<p.a;
              os=os+"*"+"(x+";
              os<<-roots[0];
              os=os+")"+"^2";
              }
              if (roots[0]==0){
              os<< p.a;
              os+="x^2";
              }
        }
        }else{
            os+="Канонический вид невозможен";
        }
    }
    delete [] roots;
    return os;
}

#endif // TPOLINOM_H
