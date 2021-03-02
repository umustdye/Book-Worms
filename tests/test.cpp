#include "gtest/gtest.h"
#include "cd.hpp"
#include "cdTest.hpp"
#include "bookTest.hpp"
#include "dvdTest.hpp"
#include "itemTest.hpp"
#include "user_test.hpp"
#include "admin_test.hpp"
#include "user.hpp"
#include "admin.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}