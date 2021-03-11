#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

#include "user_items.hpp"

#include <string>
#include <vector>

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
    QVector<userItems> userItem;
    AccountType accountType;
    int id;

public:
    Account();
    ~Account();
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
    QVector<userItems> delItem(QVector<userItems>, int);
    QVector<userItems> getItemVector();
    void setItemVector(QVector<userItems> newItems);
    void clearItemVector();
};

#endif //__ACCOUNT_HPP__
