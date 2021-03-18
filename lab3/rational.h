#ifndef Rational_H
#define Rational_H

#include <iostream>
#include<QString>
using namespace std;

class TRational
{
    int numerator;                      // Числитель
    unsigned int denominator;           // Знаменатель (>0)
    unsigned int NOK(const TRational&);  // Наименьшее общее кратное
    int NOD(const int&,const int&);     // Наибольший общий делитель
    void decrease();                    // Сократить дробь
    //TRational fraction(const double);
public:
    TRational ();
    TRational(const int&);
    TRational(const int&,const int&);
    TRational operator+ (const TRational&);   // Перегруженный оператор +
    TRational operator* (const TRational&);   // Перегруженный оператор *
    TRational operator* (const int&);        // Перегруженный оператор *с,где c-какое-либо число
    TRational operator/ (const TRational&);   // Перегруженный оператор /
    bool operator > (int);                  // Перегруженный оператор сравнения с числом
    bool operator < (int);                  // Перегруженный оператор сравнения с числом
    bool operator == (int);                 // Перегруженный оператор сравнения с числом
    bool operator == (TRational);            // Перегруженный оператор == (чтобы сравнивать дроби)
    TRational operator- (const TRational&);   // Бинарный перегруженный оператор -
    TRational operator- ();                  // Унарный перегруженный оператор -
    friend TRational sqrt(TRational);         // Дружественная функция для вычисления корня
    friend ostream& operator<< (ostream& os, const TRational&);
    friend istream& operator>> (istream& is, TRational&);

    friend QString& operator<< (QString& os, const TRational&); //Для ввода в QString
};
#endif // Rational_H
