#include "tinterface.h"
#include "tpolinom.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Лабораторная работа №3");
    setFixedSize(320,300);

    name_a = new QLabel("a = ", this);
    name_a->setGeometry(50,20,30,25);

    a_numerator = new QLineEdit("1",this);
    a_numerator->setGeometry(90,20,30,25);

    delimeter_a = new QLabel("/", this);
    delimeter_a->setGeometry(150,20,30,25);

    a_denominator = new QLineEdit("1",this);
    a_denominator->setGeometry(190,20,30,25);


    name_b = new QLabel("b = ", this);
    name_b->setGeometry(50,50,30,25);

    b_numerator = new QLineEdit("1",this);
    b_numerator->setGeometry(90,50,30,25);

    delimeter_b = new QLabel("/", this);
    delimeter_b->setGeometry(150,50,30,25);

    b_denominator = new QLineEdit("1",this);
    b_denominator->setGeometry(190,50,30,25);


    name_c = new QLabel("c = ", this);
    name_c->setGeometry(50,80,30,25);

    c_numerator = new QLineEdit("1",this);
    c_numerator->setGeometry(90,80,30,25);

    delimeter_c = new QLabel("/", this);
    delimeter_c->setGeometry(150,80,30,25);

    c_denominator = new QLineEdit("1",this);
    c_denominator->setGeometry(190,80,30,25);


    name_x = new QLabel("x = ", this);
    name_x->setGeometry(50,110,30,25);

    x_numerator = new QLineEdit("1",this);
    x_numerator->setGeometry(90,110,30,25);

    delimeter_x = new QLabel("/", this);
    delimeter_x->setGeometry(150,110,30,25);

    x_denominator = new QLineEdit("1",this);
    x_denominator->setGeometry(190,110,30,25);


    value_btn = new QPushButton("Знач.",this);
    value_btn->setGeometry(10,160,70,30);

    root_btn = new QPushButton("Корни",this);
    root_btn->setGeometry(85,160,70,30);

    print_canonic_btn = new QPushButton("Класс.",this);
    print_canonic_btn->setGeometry(160,160,70,30);

    print_classic_btn = new QPushButton("Канон.",this);
    print_classic_btn->setGeometry(235,160,70,30);

    output = new QLabel(this);
    output->setGeometry(30,210,280,50);


    connect(value_btn,SIGNAL(pressed()),this,SLOT(value()));
    connect(root_btn,SIGNAL(pressed()),this,SLOT(roots()));
    connect(print_classic_btn,SIGNAL(pressed()),this,SLOT(printClassic()));
    connect(print_canonic_btn,SIGNAL(pressed()),this,SLOT(printCanonic()));
}

TInterface::~TInterface()
{
    delete name_a;
    delete delimeter_a;
    delete a_denominator;
    delete a_numerator;

    delete name_b;
    delete delimeter_b;
    delete b_denominator;
    delete b_numerator;

    delete name_c;
    delete delimeter_c;
    delete c_denominator;
    delete c_numerator;

    delete name_x;
    delete delimeter_x;
    delete x_denominator;
    delete x_numerator;

    delete value_btn;
    delete root_btn;
    delete print_canonic_btn;
    delete print_classic_btn;

    delete output;

}

void TInterface::value(){
    number a(a_numerator->text().toInt(),a_denominator->text().toInt());
    number b(b_numerator->text().toInt(),b_denominator->text().toInt());
    number c(c_numerator->text().toInt(),c_denominator->text().toInt());
    number x(x_numerator->text().toInt(),x_denominator->text().toInt());
    TPolinom p(a,b,c);
    number value = p.getValue(x);
    QString s("p(");
    s<<x;
    s+=")=";
    s<<value;
    output->setText(s);
}

void TInterface::roots(){
    number a(a_numerator->text().toInt(),a_denominator->text().toInt());
    number b(b_numerator->text().toInt(),b_denominator->text().toInt());
    number c(c_numerator->text().toInt(),c_denominator->text().toInt());
    TPolinom p(a,b,c);
    QString s;
    number* x=p.Roots();
    if(x!=NULL){
        if(p.QuantityOfRoots()==2){
           s+="x1 = ";
           s<<x[0];
           s=s+"; x2 = ";
           s<<x[1];
           s+=";";
        }
        if(p.QuantityOfRoots()==1){
           s+="x = ";
           s<<x[0];
           s+=";";
        }
    }else{
        s+="Корней нет";
    }
   output->setText(s);
   delete x;
}

void TInterface::printCanonic(){
    number a(a_numerator->text().toInt(),a_denominator->text().toInt());
    number b(b_numerator->text().toInt(),b_denominator->text().toInt());
    number c(c_numerator->text().toInt(),c_denominator->text().toInt());
    TPolinom p(a,b,c);
    p.setPrintMethod(EPrintModeCanonic);
    QString s;
    s<<p;
    output->setText(s);
}

void TInterface::printClassic(){
    number a(a_numerator->text().toInt(),a_denominator->text().toInt());
    number b(b_numerator->text().toInt(),b_denominator->text().toInt());
    number c(c_numerator->text().toInt(),c_denominator->text().toInt());
    TPolinom p(a,b,c);
    p.setPrintMethod(EPrintModeClassic);
    QString s;
    s<<p;
    output->setText(s);
}


