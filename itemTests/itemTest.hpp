#ifndef __ITEM_TEST_HPP__
#define __ITEM_TEST__HPP__

#include "gtest/gtest.h"
#include <gmock/gmock-matchers.h>
#include "item.hpp"


TEST(ItemTest, emptyConstructor)
{
    LibraryItemComponent item;
    EXPECT_EQ(item.getTitle(), "");
    EXPECT_EQ(item.getId(), -1);
    EXPECT_EQ(item.getYear(), "");
    EXPECT_EQ(item.getQuantity(), 0);
    //empty vector to test against
    QVector<QString> testVect;
    EXPECT_EQ(item.getGenres(), testVect);
    EXPECT_EQ(item.getDescription(), "");
}

TEST(ItemTest, constructor)
{
    //series of test values
    QString title = "Catcher in the Rye";
    int quantity = 2;
    QVector<QString> testVect;
    testVect.push_back("Coming of age");
    QString year = "1959";
    int id = 23;
    QString description = "Story of some kid going through a midlife crisis.";
    LibraryItemComponent item(title, quantity, testVect, year, id, description);
    
    EXPECT_EQ(item.getTitle(), title);
    EXPECT_EQ(item.getId(), id);
    EXPECT_EQ(item.getYear(), year);
    EXPECT_EQ(item.getQuantity(), quantity);
    EXPECT_EQ(item.getGenres(), testVect);
    EXPECT_EQ(item.getDescription(), description);

}


TEST(ItemTest, stringifyItem)
{
    //series of test values
    //series of test values
    QString title = "Catcher in the Rye";
    int quantity = 2;
    QVector<QString> testVect;
    testVect.push_back("Coming of age");
    QString year = "1959";
    int id = 23;
    QString description = "Story of some kid going through a midlife crisis.";
    LibraryItemComponent item(title, quantity, testVect, year, id, description);

    QString itemStr = "";
    itemStr = "Title: "+title+"\n";
    itemStr += "Item ID: "+QString::number(id)+"\n";
    itemStr += "Year: "+year+"\n";
    itemStr += "Genres: ";
    for(auto genre:testVect)
    {
        itemStr += genre + " ";
    }
    itemStr += "\nDescription: "+description+"\n";
    itemStr += "Quantity: "+QString::number(quantity);


    EXPECT_EQ(item.stringifyItem(), itemStr);
}



#endif //__ITEM_TEST_HPP__
