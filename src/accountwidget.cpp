#include "accountwidget.h"
#include "libraryLogin.hpp"
#include "ui_accountwidget.h"

// delete this
#include "account.hpp"

AccountMainPage::AccountMainPage(Account *user, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AccountMainPage), user(user)
{
    ui->setupUi(this);

    //Set Admin button visibility
    ui->adminButton->setVisible(user->getAccountType() == admin);
}

AccountMainPage::~AccountMainPage()
{
    delete ui;
}

void AccountMainPage::on_logoutButton_clicked() {
    qDebug() << "LOGOUT";
    user->setAccountType(static_cast<AccountType>(0));
    user->setFirstName("");
    user->setId(-1);
    user->setItemType(0);
    user->setLastName("");
    user->setPassword("");
    user->setUserName("");
    emit changePage(0);
}

void AccountMainPage::on_libraryButton_clicked() {
    qDebug() << "LIBRARY";
    emit changePage(2);
}

void AccountMainPage::on_profileButton_clicked() {
    qDebug() << "PROFILE";
    UserProfileDialog u(user);
    u.exec();
}

void AccountMainPage::on_adminButton_clicked() {
    qDebug() << "ADMIN";
    emit changePage(3);
}

