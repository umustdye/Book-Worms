#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

#include "add_strat.hpp"
#include "update_strat.hpp"
#include "remove_strat.hpp"
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
    std::string userName;
    std::string password;
    std::string firstName;
    std::string lastName;
    std::vector<userItems> userItem;

    AccountType accountType;

public:
    // admin
    void addItem();
    void updateItem(int);
    void removeItem(int);
    void setItemType(int);
    int getItemType();

    // user
    void setUserName(std::string);
    void setPassword(std::string);
    void setFirstName(std::string);
    void setLastName(std::string);
    std::string getUserName();
    std::string getPassword();
    std::string getFirstName();
    std::string getLastName();

    void setAccountType(AccountType);
    AccountType getAccountType();
};

#endif //__ACCOUNT_HPP__
