#include "account_main_page.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AccountMainPage w;
    w.show();
    return a.exec();
}
