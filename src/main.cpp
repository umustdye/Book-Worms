#include "header/accountwidget.h"

#include "header/libraryLogin.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AccountMainPage w;
//    LibraryLogin w;
    w.show();
    return a.exec();
}
