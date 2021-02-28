#ifndef __DVD_TEST_HPP__
#define __DVD_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/dvd.hpp"

TEST(dvdTest, defaultConstructor)
{
    Dvd dvd;
    EXPECT_EQ(dvd.getDirector(), "");
}

TEST(dvdTest, constructor)
{
    Dvd dvd("Tim Burton");
    EXPECT_EQ(dvd.getDirector(), "Tim Burton");
    Dvd dvd1("");
    EXPECT_EQ(dvd1.getDirector(), "");
    EXPECT_EQ(dvd1.getLength(), 0);
}

TEST(dvdTest, changeDirector)
{
    Dvd dvd("Tim Burton");
    EXPECT_EQ(dvd.getDirector(), "Tim Burton");
    dvd.setDirector("John Carpenter");
    EXPECT_EQ(dvd.getDirector(), "John Carpenter");
}

#endif //__DVD_TEST_HPP__
