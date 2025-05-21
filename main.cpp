#include <QtWidgets/QApplication>
#include "pagesmanager.h"
#include "HomePage.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    pagesmanager manager;
    manager.show();

    return a.exec();
}