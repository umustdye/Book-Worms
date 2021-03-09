#include "../header/user.hpp"

void User::setUserName(std::string u) {
    this->userName = u;
}

void User::setPassword(std::string p) {
    this->password = p;
}

void User::setFirstName(std::string f) {
    this->firstName = f;
}

void User::setLastName(std::string l) {
    this->lastName = l;
}

std::string User::getUserName() {
    return this->userName;
}

std::string User::getPassword() {
    return this->password;
}

std::string User::getFirstName() {
    return this->firstName;
}

std::string User::getLastName() {
    return this->lastName;
}
