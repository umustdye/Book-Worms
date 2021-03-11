#ifndef TST_CDTEST_H
#define TST_CDTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(cdTest, cdTest)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_CDTEST_H
