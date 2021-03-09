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

void AccountMainPage::checkAdminStatus() {
    // TODO, delete new account object after including library main page code
    Account account;
    account.setAccountType(admin);


    AccountType at = account.getAccountType();

    bool isAdmin = at == admin ? true : false;

    ui->adminButton->setVisible(isAdmin);
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

