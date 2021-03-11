#ifndef __BOOK_TEST_HPP__
#define __BOOK_TEST_HPP__

#include "gtest/gtest.h"
#include <gmock/gmock-matchers.h>
#include "book.hpp"

TEST(BookTest, defaultConstructor)
{
    Book bk;
    EXPECT_EQ(bk.getAuthor(), "");
    EXPECT_EQ(bk.getPages(), 0);
}

TEST(BookTest, Constructor)
{
    //series of test values
    QString title = "GooseBumps HorrorLand: Revenge of the Living Dummy";
    int quantity = 1;
    QVector<QString> testVect;
    testVect.push_back("Horror Fiction");
    testVect.push_back("Children's");
    QString year = "2008";
    int id = 3;
    QString description = "First book in the Goosebumps HorrorLand book series.";
    QString author = "R.L. Stine";
    int pages = 135;

    Book bk(title, quantity, testVect, year, id, description, author, pages);

    EXPECT_EQ(bk.getAuthor(), author);
    EXPECT_EQ(bk.getPages(), pages);
    EXPECT_EQ(bk.getQuantity(), quantity);

}

TEST(BookTest, changedValues)
{
    //series of test values
    QString title = "It";
    int quantity = 5;
    QVector<QString> testVect;
    testVect.push_back("Horror");
    testVect.push_back("Thriller");
    QString year = "1986";
    int id = 324;
    QString description = "Horror novel.";
    QString author = "Steven King";
    int pages = 1038;

    Book bk(title, quantity, testVect, year, id, description, author, pages);
    EXPECT_EQ(bk.getAuthor(), author);
    EXPECT_EQ(bk.getPages(), pages);
    author = "Stephen King";
    pages = 1138;
    bk.setAuthor(author);
    bk.setPages(pages);
    EXPECT_EQ(bk.getAuthor(), author);
    EXPECT_EQ(bk.getPages(), pages);
}


TEST(BookTest, stringifyItem)
{
    //series of test values
    QString title = "GooseBumps HorrorLand: Revenge of the Living Dummy";
    int quantity = 1;
    QVector<QString> testVect;
    testVect.push_back("Horror Fiction");
    testVect.push_back("Children's");
    QString year = "2008";
    int id = 3;
    QString description = "First book in the Goosebumps HorrorLand book series.";
    QString author = "R.L. Stine";
    int pages = 135;

    Book bk(title, quantity, testVect, year, id, description, author, pages);

    QString item = "";
    item = "Title: "+title+"\n";
    item += "Item ID: "+QString::number(id)+"\n";
    item += "Year: "+year+"\n";
    item += "Genres: ";
    for(auto genre:testVect)
    {
        item += genre + " ";   
    }
    item += "\nDescription: "+description+"\n";
    item += "Quantity: "+QString::number(quantity);
    item += "\nAuthor: "+author+"\n";
    item += "Pages: "+QString::number(pages)+"\n";



    EXPECT_EQ(bk.stringifyItem(), item);

}


#endif //__BOOK_TEST_HPP__
