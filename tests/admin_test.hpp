#ifndef __ADMIN_TEST_HPP__
#define __ADMIN_TEST_HPP__

#include "gtest/gtest.h"

#include "admin.hpp"

TEST(AdminTest, SetGetItemType) {
    Admin admin;
    admin.setItemType(42);
    int itemType = admin.getItemType();
    EXPECT_EQ(42, itemType);
}

TEST(AdminTest, SetGetFromUserClass) {
    Admin admin;
    std::string str;

    admin.setUserName("SomethingElse");
    str = admin.getUserName();
    EXPECT_EQ("SomethingElse", str);

    admin.setPassword("keepitsecret");
    str = admin.getPassword();
    EXPECT_EQ("keepitsecret", str);

    admin.setFirstName("Dwight");
    str = admin.getFirstName();
    EXPECT_EQ("Dwight", str);

    admin.setLastName("Schrute");
    str = admin.getLastName();
    EXPECT_EQ("Schrute", str);
}

TEST(AdminTest, SetValueInStruct) {
    userItems ui;
    ui.id = 12345;
    ui.quantity = 7;
    int id = ui.id;
    int qty = ui.quantity;
    EXPECT_EQ(id, 12345);
    EXPECT_EQ(qty, 7);
}

#endif //__ADMIN_TEST_HPP__
