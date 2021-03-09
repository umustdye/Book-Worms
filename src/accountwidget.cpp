#include "header/accountwidget.h"
#include "ui_accountwidget.h"

AccountMainPage::AccountMainPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AccountMainPage)
{
    ui->setupUi(this);
    checkAdminStatus();
}

AccountMainPage::~AccountMainPage()
{
    delete ui;
}

void AccountMainPage::createAccountClass() {

}

void AccountMainPage::checkAdminStatus() {
//    ui->adminButton->setVisible(false);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("acidalia");
    db.setDatabaseName("/home/chris/Documents/qt-to-push/ChristopherCE_qt-branch/databases/items.sqlite");
    db.setUserName("mojito");
    db.setPassword("J0a1m8");
    bool ok = db.open();

    if(ok) {
        qDebug() << "Successfully opened database";

        QSqlQuery query;

        query.exec("SELECT title FROM items");

        while (query.next()) {
            QString name = query.value(0).toString();
            qDebug() << name;
        }
    }
    else {
        qDebug() << "Cannot open database.";
    }
}

void AccountMainPage::on_logoutButton_clicked() {
    qDebug() << "LOGOUT";
}

void AccountMainPage::on_libraryButton_clicked() {
    qDebug() << "LIBRARY";
}

void AccountMainPage::on_profileButton_clicked() {
    qDebug() << "PROFILE";
    UserProfileDialog u;
    u.exec();
}

void AccountMainPage::on_adminButton_clicked() {
    qDebug() << "ADMIN";
}

