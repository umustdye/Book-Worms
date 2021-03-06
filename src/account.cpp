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
void Account::setUserName(std::string u) {
    this->userName = u;
}

void Account::setPassword(std::string p) {
    this->password = p;
}

void Account::setFirstName(std::string f) {
    this->firstName = f;
}

void Account::setLastName(std::string l) {
    this->lastName = l;
}

std::string Account::getUserName() {
    return this->userName;
}

std::string Account::getPassword() {
    return this->password;
}

std::string Account::getFirstName() {
    return this->firstName;
}

std::string Account::getLastName() {
    return this->lastName;
}

void Account::setAccountType(AccountType at) {
    this->accountType = at;
}

AccountType Account::getAccountType() {
    return this->accountType;
}
