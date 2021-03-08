#include "accountwidget.h"
#include "ui_accountwidget.h"
#include <QDebug>

AccountMainPage::AccountMainPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AccountMainPage)
{
    ui->setupUi(this);
    //checkAdminStatus();
}

AccountMainPage::~AccountMainPage()
{
    delete ui;
}

void AccountMainPage::createAccountClass() {

}

void AccountMainPage::checkAdminStatus() {
    ui->adminButton->setVisible(false);
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

