#include "polinom.h"
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

void TPolinom::setPrintMethod(EPrintMode ePrintMethod)
{
    this->printMode = ePrintMethod;
}

number TPolinom::getValue(number x){
    return a*x*x+b*x+c;
}

int TPolinom::getQuantityOfRoots(){
    if(getDiscriminant()>0){
        return 2;
    }
    if(getDiscriminant()==0){
        return 1;
    }
    if(getDiscriminant()<0){
        return 0;
    }
    return -1;
}

number TPolinom::getDiscriminant(){
    return b*b - a*c*4;
}


number* TPolinom::getRoots(){
    number * roots;
    if(getQuantityOfRoots()==2){
        roots = new number[2];
        roots[0] = ((-b) + sqrt(getDiscriminant()))/(a*2);
        roots[1] = ((-b) - sqrt(getDiscriminant()))/(a*2);
        if(!isValidRoots(roots,2)){
            roots = NULL;
        }
    }else if(getQuantityOfRoots()==1){
        roots = new number[1];
         roots[0] = -b/(a*2);
         if(!isValidRoots(roots,1)){
             roots = NULL;
         }
    }else{
        roots = NULL;
    }
    return roots;
}

bool TPolinom:: isValidRoots(number*roots,int quantityOfRoots){
    if(quantityOfRoots==2){
        return (roots[0]+roots[1])==-(b/a) && (roots[0]*roots[1])==(c/a) ;
    }else if(quantityOfRoots==1){
        return (roots[0]+roots[0])==-(b/a) && roots[0]*roots[0]==(c/a) ;
    }else{
        return false;
    }
}
ostream& operator << (ostream& os, TPolinom& p){
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
    number*roots = p.getRoots();
    if(p.printMode == EPrintModeCanonic){
        if(roots!=NULL){
        if(p.getQuantityOfRoots()==2){
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
        }else if(p.getQuantityOfRoots()==1){
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
            os<<"Корней нет,\nканонический вид невозможен";
        }
    }
    delete [] roots;
    return os;
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
    number*roots = p.getRoots();
    if(p.printMode == EPrintModeCanonic){
        if(roots!=NULL){
        if(p.getQuantityOfRoots()==2){
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
        }else if(p.getQuantityOfRoots()==1){
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
            os+="Корней нет,\nканонический вид невозможен";
        }
    }
    delete [] roots;
    return os;
}



