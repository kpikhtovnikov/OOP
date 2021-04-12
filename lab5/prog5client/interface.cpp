#include "interface.h"
#include "common.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Лабораторная работа №5");
        setFixedSize(320,360);

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

        print_canonic_btn = new QPushButton("Канон.",this);
        print_canonic_btn->setGeometry(160,160,70,30);

        print_classic_btn = new QPushButton("Класс.",this);
        print_classic_btn->setGeometry(235,160,70,30);

        integer_mode = new QRadioButton("Целые",this);
        integer_mode->setGeometry(60,230,100,30);
        integer_mode->setChecked(true);

        rational_mode = new QRadioButton("Дроби",this);
        rational_mode->setGeometry(200,230,100,30);

        output = new QLabel(this);
        output->setGeometry(30,300,280,50);


    connect(value_btn,SIGNAL(pressed()),this,SLOT(formRequest()));
    connect(print_classic_btn,SIGNAL(pressed()),this,SLOT(formRequest()));
    connect(print_canonic_btn,SIGNAL(pressed()),this,SLOT(formRequest()));
    connect(root_btn,SIGNAL(pressed()),this,SLOT(formRequest()));
}

TInterface::~TInterface()
{
    delete integer_mode;
    delete rational_mode;
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


    delete output;

    delete value_btn;
    delete root_btn;
    delete print_canonic_btn;
    delete print_classic_btn;
}

void TInterface::formRequest()
{
    QString msg;
    if(integer_mode->isChecked()){
        msg<<QString().setNum(INTEGER_MODE);
        msg << a_numerator->text();
        msg << b_numerator->text();
        msg << c_numerator->text();
    }else{
        msg<<QString().setNum(RATIONAL_MODE);
        msg << a_numerator->text() << a_denominator->text();
        msg << b_numerator->text() << b_denominator->text();
        msg << c_numerator->text() << c_denominator->text();
    }

    QPushButton *btn = (QPushButton*)sender();
    if (btn == value_btn)
    {
        msg << QString().setNum(VALUE_REQUEST);
        if(integer_mode->isChecked()){
            msg << x_numerator->text();
        }else{
            msg << x_numerator->text() << x_denominator->text();
        }

    }
    if (btn == print_classic_btn)
        msg << QString().setNum(PRINT_CLASSIC_REQUEST);
    if(btn == print_canonic_btn)
        msg << QString().setNum(PRINT_CANONIC_REQUEST);
    if(btn == root_btn)
        msg << QString().setNum(ROOTS);
    emit request(msg);
}

void TInterface::answer(QString msg)
{
    QString text;
    int p = msg.indexOf(separator);
    int t = msg.left(p).toInt();
    msg = msg.mid(p+1,msg.length()-p-2);
    switch (t)
    {
        case VALUE_ANSWER:
            text = "p(";
            p = msg.indexOf(separator);
            text += msg.left(p);
            text += ")";
            text += " = ";
            text += msg.right(msg.length()-p-1);
            output->setText(text);
            break;
        case ROOTS_ANSWER:
            text = msg;
            output->setText(text);
            break;
        case PRINT_ANSWER:
            text = "";
            text += msg;
            output->setText(text);
            break;
        default: break;
    }
}
