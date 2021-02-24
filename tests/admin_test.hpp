#ifndef __ADMIN_TEST_HPP__
#define __ADMIN_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/admin.hpp"

TEST(AdminTest, SetGetItemType) {
    Admin admin;
    admin.setItemType(42);
    int itemType = admin.getItemType();
    EXPECT_EQ(42, itemType);
}

#endif //__ADMIN_TEST_HPP__
