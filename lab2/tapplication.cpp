#include "tapplication.h"
#include "tpolinom.h"
#include "number.h"
#include <iostream>
using namespace std;

TApplication::TApplication()
{

}

void TApplication:: exec(){
    int ch;
    number a=1, b=2, c=1;
        while (true){
            ch = menu();
            switch (ch)
            {
            case 1:
            {
                cout <<"Enter a,b,c:"<<endl;
                cout << "a= "; cin >>a;
                cout << "b= "; cin>>b;
                cout << "c= "; cin>>c;
                if (a==0)
                {
                    cout<<"it's not a quadratic equation";
                    return;
                }
                break;
            }
            case 2:
            {
                    TPolinom p(a,b,c);
                    number x;
                    cout <<"Enter x:" << endl;
                    cout <<">";
                    cin >> x;
                    cout <<"P("<<x<<")="<<p.getValue(x) << endl;
                    break;
            }

            case 3:
            {
                TPolinom p(a,b,c);
                number *x=p.Roots();
                if(x!=NULL){
                    if(p.QuantityOfRoots()==2){
                        cout<<"There are two roots:"<<" "
                            <<"x1="<<x[0]<<"\t"<<"x2="<<x[1]<<endl;
                    }
                    if(p.QuantityOfRoots()==1){
                         cout<<"There is one root:"<<" ""x="<<x[0]<<endl;
                    }
                }else{
                    cout<<"No roots on the field of rational"<<endl;
                }
                delete x;
                break;
            }
            case 4:
            {
                TPolinom p(a,b,c);
                p.setPrintMethod(EPrintModeClassic);
                cout << p << endl;
                break;
            }

            case 5:
            {
                TPolinom p(a,b,c);
                p.setPrintMethod(EPrintModeCanonic);
                cout << p << endl;
                break;
            }
            case 0:{
                return;
            }

            default:{
                 break;
            }

            }
        }
    }

int TApplication::menu(){
    int ch;
    cout <<"1- coefficients" << endl;
    cout <<"2- value" << endl;
    cout <<"3- roots" << endl;
    cout <<"4- print (classic)"<< endl;
    cout <<"5- print (canonical)"<<endl;
    cout <<"0- exit"<<">"<< endl;
    cout <<">";
    cin >> ch;
    return ch;
}



