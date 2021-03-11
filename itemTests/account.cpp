#include "account.hpp"

// admin
void Account::addItem() {

}

void Account::updateItem(int id) {

}

void Account::removeItem(int id) {

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

void Account::deleteItem(userItems u) {

}
