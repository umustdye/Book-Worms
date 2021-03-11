#ifndef __DVD_TEST_HPP__
#define __DVD_TEST_HPP__

#include "gtest/gtest.h"
#include <gmock/gmock-matchers.h>
#include "dvd.hpp"

TEST(dvdTest, defaultConstructor)
{
    Dvd dvd;
    EXPECT_EQ(dvd.getDirector(), "");
    EXPECT_EQ(dvd.getLength(), 0);
}

TEST(dvdTest, constructor)
{ 
    //series of test values
    QString title = "Corpse Bride";
    int quantity = 3;
    QVector<QString> testVect;
    testVect.push_back("Romance");
    testVect.push_back("Musical");
    QString year = "2005";
    int id = 3;
    QString description = "Stop-animated musical fantasy.";
    QString director = "Tim Burton";
    int length = 78;

    Dvd dvd(title, quantity, testVect, year, id, description, director, length);
    EXPECT_EQ(dvd.getDirector(), director);
    EXPECT_EQ(dvd.getLength(), length);
    EXPECT_EQ(dvd.getId(), id);
    EXPECT_EQ(dvd.getTitle(), title);
    EXPECT_EQ(dvd.getYear(), year);
}

TEST(dvdTest, changeValues)
{
    //series of test values
    QString title = "Coraline";
    int quantity = 5;
    QVector<QString> testVect;
    testVect.push_back("Horror");
    testVect.push_back("Fantasy");
    QString year = "2009";
    int id = 42;
    QString description = "American stop-motion animated dark fantasy film.";
    QString director = "Tim Burton";
    int length = 10;

    Dvd dvd(title, quantity, testVect, year, id, description, director, length);

    EXPECT_EQ(dvd.getDirector(), director);
    EXPECT_EQ(dvd.getLength(), length);
    director = "Henry Selick";
    length = 100;
    dvd.setDirector(director);
    dvd.setLength(length);
    EXPECT_EQ(dvd.getDirector(), director);
    EXPECT_EQ(dvd.getLength(), length);
}

TEST(dvdTest, stringifyItem)
{ 
    //series of test values
    QString title = "Corpse Bride";
    int quantity = 3;
    QVector<QString> testVect;
    testVect.push_back("Romance");
    testVect.push_back("Musical");
    QString year = "2005";
    int id = 3;
    QString description = "Stop-animated musical fantasy.";
    QString director = "Tim Burton";
    int length = 78;

    Dvd dvd(title, quantity, testVect, year, id, description, director, length);


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
    item += "\nDirector: "+director+"\n";
    item += "Length: "+QString::number(length)+" minutes\n";

    EXPECT_EQ(dvd.stringifyItem(), item);
}


#endif //__DVD_TEST_HPP__
