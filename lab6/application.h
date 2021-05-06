#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include<QApplication>
#include "interface.h"

class TApplication : public QApplication
{
    Q_OBJECT
    TInterface * interface;

public:
    TApplication(int, char**);
    ~TApplication();
};

#endif // TAPPLICATION_H
