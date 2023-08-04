#include "EmployeeSystemFrontends.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EmployeeSystemFrontends w;
    w.show();
    return a.exec();
}
