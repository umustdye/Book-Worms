#include "libraryLogin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LibraryLogin w;
    w.show();
    return a.exec();
}
