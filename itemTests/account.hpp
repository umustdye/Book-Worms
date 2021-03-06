#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

#include "user_items.hpp"



enum AccountType {
    user, admin
};

class Account {
private:
    // admin
    int itemType;

    // user
    QString userName;
    QString password;
    QString firstName;
    QString lastName;
    std::vector<userItems> userItem;

    AccountType accountType;
    int id;

public:
    // admin
    void addItem();
    void updateItem(int);
    void removeItem(int);
    void setItemType(int);
    int getItemType();

    // user
    void setUserName(QString);
    void setPassword(QString);
    void setFirstName(QString);
    void setLastName(QString);
    QString getUserName();
    QString getPassword();
    QString getFirstName();
    QString getLastName();

    void setAccountType(AccountType);
    AccountType getAccountType();
    void setId(int);
    int getId();

    void addItem(userItems);
    void deleteItem(userItems);
};

#endif //__ACCOUNT_HPP__
