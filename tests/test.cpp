#include "gtest/gtest.h"

#include "../tests/user_test.hpp"
#include "../tests/admin_test.hpp"
#include "../header/user.hpp"
#include "../header/admin.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
