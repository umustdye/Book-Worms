#include "header/accountwidget.h"
#include "header/libraryLogin.hpp"
#include "ui_accountwidget.h"

// delete this
#include "header/account.hpp"

AccountMainPage::AccountMainPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AccountMainPage)
{
    ui->setupUi(this);
    
    // delete this
    tempAccount();
    
    checkAdminStatus();
}

AccountMainPage::~AccountMainPage()
{
    delete ui;
}


// delete this
void AccountMainPage::tempAccount() {
    a->setUserName("userName");
    a->setPassword("password");
    a->setFirstName("firstName69");
    a->setLastName("lastName");
    AccountType at = admin;
    a->setAccountType(at);
    a->setId(0);

    userItems ui1;
    ui1.id = 2;
    ui1.quantity = 10;
    QDateTime dueDate = QDateTime::fromString("Tue March 23 2021 11:59 pm", "ddd MMMM d yyyy h:m ap");
    ui1.dueDate = dueDate;
    a->addItem(ui1);
    ui1.id = 3;
    ui1.quantity = 10;
    dueDate = QDateTime::fromString("Tue March 23 2021 11:59 pm", "ddd MMMM d yyyy h:m ap");
    ui1.dueDate = dueDate;
    a->addItem(ui1);
    ui1.id = 4;
    ui1.quantity = 10;
    dueDate = QDateTime::fromString("Tue March 23 2021 11:59 pm", "ddd MMMM d yyyy h:m ap");
    ui1.dueDate = dueDate;
    a->addItem(ui1);

    QVector<userItems> v = a->getItemVector();

    // delete this
//    qDebug() << a->getUserName();
//    qDebug() << a->getPassword();
//    qDebug() << a->getFirstName();
//    qDebug() << a->getLastName();
//    qDebug() << a->getAccountType();
//    qDebug() << a->getId();

//    for(int i = 0; i < v.count(); i++) {
//        qDebug() << v[i].id;
//        qDebug() << v[i].quantity;
//        qDebug() << v[i].dueDate;
//    }

}

void AccountMainPage::checkAdminStatus() {

    // change to correct variable, replace 'a'
    AccountType at = a->getAccountType();

    bool isAdmin = at == admin ? true : false;

    ui->adminButton->setVisible(isAdmin);
}

void AccountMainPage::on_logoutButton_clicked() {
    qDebug() << "LOGOUT";

    // TODO, delete user/admin object upon logout, just need the variable name from library main page
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

