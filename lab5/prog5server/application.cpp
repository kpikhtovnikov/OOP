#include "application.h"
#include "polinom.h"
#include "common.h"
#include <QString>
#include <rational.h>

using namespace std;

QString& operator <<(QString &s, const int& rational)
{
    s += QString().setNum(rational);
    return s;
}

QByteArray& operator>>(QByteArray& arr, int& r){
    int p = arr.indexOf(separator);
    if(p > 0){
        r = atoi(arr.left(p));
        arr = arr.right(arr.length()-p-1);
    }
    return arr;
}

TApplication::TApplication(int argc, char *argv[])
            : QCoreApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));
}

void TApplication::recieve(QByteArray msg)
{
    QString answer, s;
    int pos = msg.indexOf(separator);
    int t,mode = msg.left(pos).toInt();

    msg = msg.right(msg.length()-pos-1);
    if(mode == RATIONAL_MODE){
        TRational a, b, c, x, v;
        msg>>a>>b>>c;
        TPolinom<TRational> p(a,b,c);

        pos = msg.indexOf(separator);
        t = msg.left(pos).toInt();
        switch (t)
        {
            case VALUE_REQUEST:
                msg = msg.right(msg.length()-pos-1);
                msg>>x;
                v = p.getValue(x);
                s<<(QString)x<<(QString)v;
                answer<<QString().setNum(VALUE_ANSWER);
                answer += s;
                break;
        case ROOTS:{
            TRational* x=p.Roots();
            if(x!=NULL){
                if(p.QuantityOfRoots()==2){
                   s+="x1 = ";
                   s<<x[0];
                   s=s+"; x2 =  ";
                   s<<x[1];
                   s+="; ";
                }
                if(p.QuantityOfRoots()==1){
                   s+="x =  ";
                   s<<x[0];
                   s+=";";
                }
            }else{
                s+="Корней нет ";
            }
            answer<<QString().setNum(ROOTS_ANSWER);
            answer += s;
            break;
            }
            case PRINT_CANONIC_REQUEST:
                p.setPrintMethod(EPrintModeCanonic);
                s<<p;
                answer<<QString().setNum(PRINT_ANSWER)<<s;
                break;
            case PRINT_CLASSIC_REQUEST:
                p.setPrintMethod(EPrintModeClassic);
                s<<p;
                answer<<QString().setNum(PRINT_ANSWER)<<s;
                break;
            default: return;
        }
    }

    if(mode == INTEGER_MODE){
        int a, b, c, x, v;
        msg>>a>>b>>c;
        TPolinom<int> p(a,b,c);

        pos = msg.indexOf(separator);
        t = msg.left(pos).toInt();
        switch (t)
        {
            case VALUE_REQUEST:
                msg = msg.right(msg.length()-pos-1);
                msg>>x;
                v = p.getValue(x);
                s<<QString().setNum(x)<<QString().setNum(v);
                answer<<QString().setNum(VALUE_ANSWER);
                answer += s;
                break;
        case ROOTS:{
            int* x=p.Roots();
            if(x!=NULL){
                if(p.QuantityOfRoots()==2){
                   s+="x1 = ";
                   s<<x[0];
                   s=s+"; x2 =  ";
                   s<<x[1];
                   s+="; ";
                }
                if(p.QuantityOfRoots()==1){
                   s+="x =  ";
                   s<<x[0];
                   s+=";";
                }
            }else{
                s+="Корней нет ";
            }
            answer<<QString().setNum(ROOTS_ANSWER);
            answer += s;
            break;
            }
            case PRINT_CANONIC_REQUEST:
                p.setPrintMethod(EPrintModeCanonic);
                s<<p;
                answer<<QString().setNum(PRINT_ANSWER)<<s;
                break;
            case PRINT_CLASSIC_REQUEST:
                p.setPrintMethod(EPrintModeClassic);
                s<<p;
                answer<<QString().setNum(PRINT_ANSWER)<<s;
                break;
            default: return;
        }
    }


    comm->send(QByteArray().append(answer));
}
