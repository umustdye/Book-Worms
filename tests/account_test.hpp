#ifndef __ACCOUNT_TEST_HPP__
#define __ACCOUNT_TEST_HPP__

#include "gtest/gtest.h"

#include "account.hpp"

TEST(AccountTest, SetGetUsername) {
    Account account;
    account.setUserName("Parcival");
    std::string userName = account.getUserName();
    EXPECT_EQ("Parcival", userName);
}

TEST(AccountTest, SetGetPassword) {
    Account account;
    account.setPassword("password");
    std::string password = account.getPassword();
    EXPECT_EQ("password", password);
}

TEST(AccountTest, SetGetFirstName) {
    Account account;
    account.setFirstName("Peter");
    std::string firstName = account.getFirstName();
    EXPECT_EQ("Peter", firstName);
}

TEST(AccountTest, SetGetLastName) {
    Account account;
    account.setLastName("Southward");
    std::string lastName = account.getLastName();
    EXPECT_EQ("Southward", lastName);
}

TEST(AccountTest, SetGetTwice) {
    Account account;
    std::string str;
    account.setUserName("ExecutiveGoth");
    str = account.getUserName();
    EXPECT_EQ("ExecutiveGoth", str);
    account.setUserName("SomethingElse");
    str = account.getUserName();
    EXPECT_EQ("SomethingElse", str);

    account.setPassword("keepitsecret");
    str = account.getPassword();
    EXPECT_EQ("keepitsecret", str);
    account.setPassword("keepitsafe");
    str = account.getPassword();
    EXPECT_EQ("keepitsafe", str);

    account.setFirstName("Dwight");
    str = account.getFirstName();
    EXPECT_EQ("Dwight", str);
    account.setFirstName("Michael");
    str = account.getFirstName();
    EXPECT_EQ("Michael", str);

    account.setLastName("Schrute");
    str = account.getLastName();
    EXPECT_EQ("Schrute", str);
    account.setLastName("Scott");
    str = account.getLastName();
    EXPECT_EQ("Scott", str);
}


TEST(AccountTest, SetGetItemType) {
    Account account;
    account.setItemType(42);
    int itemType = account.getItemType();
    EXPECT_EQ(42, itemType);
}

TEST(AccountTest, SetGetEmpty) {
    Account account;
    std::string str;

    account.setUserName("");
    str = account.getUserName();
    EXPECT_EQ("", str);

    account.setPassword("");
    str = account.getPassword();
    EXPECT_EQ("", str);

    account.setFirstName("");
    str = account.getFirstName();
    EXPECT_EQ("", str);

    account.setLastName("");
    str = account.getLastName();
    EXPECT_EQ("", str);
}

TEST(AccountTest, SetGetFromAccountClass) {
    Account account;
    std::string str;

    account.setUserName("SomethingElse");
    str = account.getUserName();
    EXPECT_EQ("SomethingElse", str);

    account.setPassword("keepitsecret");
    str = account.getPassword();
    EXPECT_EQ("keepitsecret", str);

    account.setFirstName("Dwight");
    str = account.getFirstName();
    EXPECT_EQ("Dwight", str);

    account.setLastName("Schrute");
    str = account.getLastName();
    EXPECT_EQ("Schrute", str);
}

TEST(AccountTest, SetValueInStruct) {
    userItems ui;
    ui.id = 12345;
    ui.quantity = 7;
    int id = ui.id;
    int qty = ui.quantity;
    EXPECT_EQ(id, 12345);
    EXPECT_EQ(qty, 7);
}

TEST(AccountTest, SetGetAccountType) {
    Account account;
    account.setAccountType(user);
    AccountType at0 = user;
    EXPECT_EQ(at0, account.getAccountType());
    account.setAccountType(admin);
    AccountType at1 = admin;
    EXPECT_EQ(at1, account.getAccountType());
}

TEST(AccountTest, SetGetId) {
    Account account;
    account.setId(123456);
    int id = account.getId();
    EXPECT_EQ(123456, id);
}

#endif //__ACCOUNT_TEST_HPP__
