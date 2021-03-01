#ifndef __USER_TEST_HPP__
#define __USER_TEST_HPP__

#include "gtest/gtest.h"

#include "user.hpp"

TEST(UserTest, SetGetUsername) {
    User user;
    user.setUserName("Parcival");
    std::string userName = user.getUserName();
    EXPECT_EQ("Parcival", userName);
}

TEST(UserTest, SetGetPassword) {
    User user;
    user.setPassword("password");
    std::string password = user.getPassword();
    EXPECT_EQ("password", password);
}

TEST(UserTest, SetGetFirstName) {
    User user;
    user.setFirstName("Peter");
    std::string firstName = user.getFirstName();
    EXPECT_EQ("Peter", firstName);
}

TEST(UserTest, SetGetLastName) {
    User user;
    user.setLastName("Southward");
    std::string lastName = user.getLastName();
    EXPECT_EQ("Southward", lastName);
}

TEST(UserTest, SetGetTwice) {
    User user;
    std::string str;
    user.setUserName("ExecutiveGoth");
    str = user.getUserName();
    EXPECT_EQ("ExecutiveGoth", str);
    user.setUserName("SomethingElse");
    str = user.getUserName();
    EXPECT_EQ("SomethingElse", str);
    
    user.setPassword("keepitsecret");
    str = user.getPassword();
    EXPECT_EQ("keepitsecret", str);
    user.setPassword("keepitsafe");
    str = user.getPassword();
    EXPECT_EQ("keepitsafe", str);
    
    user.setFirstName("Dwight");
    str = user.getFirstName();
    EXPECT_EQ("Dwight", str);
    user.setFirstName("Michael");
    str = user.getFirstName();
    EXPECT_EQ("Michael", str);

    user.setLastName("Schrute");
    str = user.getLastName();
    EXPECT_EQ("Schrute", str);

    user.setLastName("Scott");
    str = user.getLastName();
    EXPECT_EQ("Scott", str);
}

#endif //__USER_TEST_HPP__
