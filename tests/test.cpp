#include "gtest/gtest.h"

#include "../header/cd.hpp"
#include "cdTest.hpp"
#include "bookTest.hpp"
#include "dvdTest.hpp"
#include "itemTest.hpp"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
