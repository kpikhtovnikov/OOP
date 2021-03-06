#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class Rational
{
    int numerator;                      // Числитель
    unsigned int denominator;           // Знаменатель (>0)
    unsigned int NOK(const Rational&);  // Наименьшее общее кратное
    int NOD(const int&,const int&);     // Наибольший общий делитель
    void decrease();                    // Сократить дробь
public:
    Rational ();
    Rational(const int&);
    Rational operator+ (const Rational&);   // Перегруженный оператор +
    Rational operator* (const Rational&);   // Перегруженный оператор *
    Rational operator* (const int&);        // Перегруженный оператор *с,где c-какое-либо число
    Rational operator/ (const Rational&);   // Перегруженный оператор /
    bool operator > (int);                  // Перегруженный оператор сравнения с числом
    bool operator < (int);                  // Перегруженный оператор сравнения с числом
    bool operator == (int);                 // Перегруженный оператор сравнения с числом
    bool operator == (Rational);            // Перегруженный оператор == (чтобы сравнивать дроби)
    Rational operator- (const Rational&);   // Бинарный перегруженный оператор -
    Rational operator- ();                  // Унарный перегруженный оператор -
    friend Rational sqrt(Rational);         // Дружественная функция для вычисления корня
    friend ostream& operator<< (ostream& os, const Rational&);
    friend istream& operator>> (istream& is, Rational&);
};
#endif // RATIONAL_H
