#ifndef __ITEM_TEST_HPP__
#define __ITEM_TEST__HPP__

#include "gtest/gtest.h"

#include "../header/item.hpp"
#include <vector>
#include <string>
using std::vector;
using std::string;

TEST(ItemTest, emptyConstructor)
{
    LibraryItemComponent item;
    EXPECT_EQ(item.getTitle(), "");
    EXPECT_EQ(item.getId(), -1);
    EXPECT_EQ(item.getYear(), "");
    EXPECT_EQ(item.getQuantity(), 0);
    //empty vector to test against
    std::vector<std::string> testVect;
    EXPECT_EQ(item.getGenres(), testVect);
    EXPECT_EQ(item.getDescription(), "");
}

TEST(ItemTest, constructor)
{
    //series of test values
    string title = "Catcher in the Rye";
    int quantity = 2;
    std::vector<std::string> testVect;
    testVect.push_back("Coming of age");
    std::string year = "1959";
    int id = 23;
    string description = "Story of some kid going through a midlife crisis.";
    LibraryItemComponent item(title, quantity, testVect, year, id, description);
    
    EXPECT_EQ(item.getTitle(), title);
    EXPECT_EQ(item.getId(), id);
    EXPECT_EQ(item.getYear(), year);
    EXPECT_EQ(item.getQuantity(), quantity);
    EXPECT_EQ(item.getGenres(), testVect);
    EXPECT_EQ(item.getDescription(), description);

}

#endif //__ITEM_TEST_HPP__
