#include "account.hpp"

// admin
Account::Account()
{
    userName = "";
    password = "";
    firstName = "";
    lastName = "";
    accountType = user;
    id = -1;
}

Account::~Account()
{
}

void Account::setItemType(int type) {
    this->itemType = type;
}

int Account::getItemType() {
    return this->itemType;
}

// user
void Account::setUserName(QString u) {
    this->userName = u;
}

void Account::setPassword(QString p) {
    this->password = p;
}

void Account::setFirstName(QString f) {
    this->firstName = f;
}

void Account::setLastName(QString l) {
    this->lastName = l;
}

QString Account::getUserName() {
    return this->userName;
}

QString Account::getPassword() {
    return this->password;
}

QString Account::getFirstName() {
    return this->firstName;
}

QString Account::getLastName() {
    return this->lastName;
}

// user and admin
void Account::setAccountType(AccountType at) {
    this->accountType = at;
}

AccountType Account::getAccountType() {
    return this->accountType;
}

void Account::setId(int i) {
    this->id = i;
}

int Account::getId() {
    return this->id;
}

void Account::addItem(userItems u) {
    this->userItem.push_back(u);
}

QVector<userItems> Account::delItem(QVector<userItems> ui, int id) {
    for(int i = 0; i < ui.size(); i++) {
        if(ui[i].id == id) {
            ui.remove(i);
        }
    }

    return ui;
}

QVector<userItems> Account::getItemVector() {
    return this->userItem;
}

void Account::setItemVector(QVector<userItems> newItems)
{
    this->userItem = newItems;
}

void Account::clearItemVector()
{
    this->userItem.clear();
}
