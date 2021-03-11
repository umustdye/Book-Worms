//#include "tst_cdtest.h"
//ITEM COMPOSITE TESTS
#include "cdTest.hpp"
#include "bookTest.hpp"
#include "dvdTest.hpp"
#include "collectionTest.hpp"
#include "itemTest.hpp"
//-------------------------------------------------
//ACCOUNT TESTS
#include "account_test.hpp"
#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
