#include "header/account_page_user_profile.h"
#include "header/accountwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    AccountPageUserProfile w;
    AccountMainPage w;
    w.show();
    return a.exec();
}
