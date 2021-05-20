#include "Tapplication.h"
#include "Triangle.h"
#include "Square.h"
#include <QList>
#include <QDebug>
#include <iostream>
using namespace std;

TApplication::TApplication()
{

}

void TApplication:: exec(){
    int ch;
    int a, b, c, angle, beta;
    while(true) {

        cout << "\tMENU:\n";
        cout << "1. Triangle\n";
        cout << "2. Square\n";
        cout << "3. Rhombus\n";
        cout << "4. Rectangle\n";
        cout << "5. Quadrangle\n";
        cout << "6. Parallelogram\n";
        cout << "7. Polygon\n";
        cout << "0. Exit\n";

        cin >> ch;

        if(ch == 0)
            break;
        switch(ch) {
        case 1: {
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
            cout << "angle = ";
            cin >> angle;
            Triangle * tr = new Triangle(a, b, angle);
            qDebug() << "area: " << tr->area() << "\nperimetr: " << tr->perimetr() << endl;
            break;
        }
        case 2: {
            cout << "a = ";
            cin >> a;
            Square * sq = new Square(a);
            qDebug() << "area: " << sq->area() << "\nperimetr: " << sq->perimetr() << endl;
            break;
        }
        case 3: {
            cout << "a = ";
            cin >> a;
            cout << "angle = ";
            cin >> angle;
            Rhombus * rh = new Rhombus(a, angle);
            qDebug() << "area: " << rh->area() << "\nperimetr: " << rh->perimetr() << endl;
            break;
        }
        case 4: {
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
            Rectangle * rect = new Rectangle(a, b);
            qDebug() << "area: " << rect->area() << "\nperimetr: " << rect->perimetr() << endl;
            break;
        }
        case 5: {
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
            cout << "c = ";
            cin >> c;
            cout << "alpha = ";
            cin >> angle;
            cout << "beta = ";
            cin >> beta;
            Quadrangle * q = new Quadrangle(a, b, c, angle, beta);
            qDebug() << "area: " << q->area() << "\nperimetr: " << q->perimetr() << endl;
            break;
        }
        case 6: {
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
            cout << "angle = ";
            cin >> angle;
            Parallelogram * p = new Parallelogram(a, b, angle);
            qDebug() << "area: " << p->area() << "\nperimetr: " << p->perimetr() << endl;
            break;
        }
        case 7: {
            string edges, angles;
            cout << "Enter the edges with a space: ";
            std::getline(cin >> std::ws, edges);
            cout << "Enter the angles with a space: ";
            std::getline(cin >> std::ws, angles);
            QStringList e = QString::fromStdString(edges.c_str()).split(" ");
            QStringList ang = QString::fromStdString(angles.c_str()).split(" ");
            QList<double> edgPoly, angPoly;
            for(int i = 0; i < e.size(); i++) {
                edgPoly.append(e[i].toDouble());
                angPoly.append(ang[i].toDouble());
            }
            Polygon * poly = new Polygon(edgPoly, angPoly);
            qDebug() << "area: " << poly->area() << "\nperimetr: " << poly->perimetr() << endl;
            break;
        }
        default:
            break;
        }
    }
}



