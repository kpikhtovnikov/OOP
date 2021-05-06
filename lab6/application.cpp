#include "application.h"

TApplication::TApplication(int argc, char ** argv) : QApplication(argc, argv)
{
 interface = new TInterface();
 interface->show();
}

TApplication::~TApplication(){
    delete interface;
}
