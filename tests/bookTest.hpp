#ifndef __BOOK_TEST_HPP__
#define __BOOK_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/book.hpp"

TEST(BookTest, defaultConstructor)
{
    Book bk;
    EXPECT_EQ(bk.getAuthor(), "");
}

TEST(BookTest, Constructor)
{
    Book bk("Tom Greene");
    EXPECT_EQ(bk.getAuthor(), "Tom Greene");

    Book bk2("");
    EXPECT_EQ(bk2.getAuthor(), "");
}

TEST(BookTest, changedAuthor)
{
    Book bk("Tom Greene");
    EXPECT_EQ(bk.getAuthor(), "Tom Greene");
    bk.setAuthor("Stephen King");
    EXPECT_EQ(bk.getAuthor(), "Stephen King");
}

#endif //__BOOK_TEST_HPP__
