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

    // delete this
    tempItems();

    //Set Admin button visibility
    ui->adminButton->setVisible(user->getAccountType() == admin);
}

AccountMainPage::~AccountMainPage()
{
    delete ui;
}

// delete this
void AccountMainPage::tempItems() {

    // create temporary items
    user->setUserName("userName");
    user->setPassword("password");
    user->setFirstName("firstName");
    user->setLastName("lastName");
    AccountType at = admin;
    user->setAccountType(at);
    user->setId(0);
    userItems ui1;
    ui1.id = 2;
    ui1.quantity = 10;
    QDateTime dueDate = QDateTime::fromString("Tue March 23 2021 11:59 pm", "ddd MMMM d yyyy h:m ap");
    ui1.dueDate = dueDate;
    user->addItem(ui1);
    ui1.id = 3;
    ui1.quantity = 11;
    dueDate = QDateTime::fromString("Tue March 23 2021 11:59 pm", "ddd MMMM d yyyy h:m ap");
    ui1.dueDate = dueDate;
    user->addItem(ui1);
    ui1.id = 4;
    ui1.quantity = 12;
    dueDate = QDateTime::fromString("Tue March 23 2021 11:59 pm", "ddd MMMM d yyyy h:m ap");
    ui1.dueDate = dueDate;
    user->addItem(ui1);
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

