#ifndef __DVD_TEST_HPP__
#define __DVD_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/dvd.hpp"

TEST(dvdTest, defaultConstructor)
{
    Dvd dvd;
    EXPECT_EQ(dvd.getDirector(), "");
    EXPECT_EQ(dvd.getLength(), 0);
}

TEST(dvdTest, constructor)
{ 
    //series of test values
    string title = "Corpse Bride";
    int quantity = 3;
    std::vector<std::string> testVect;
    testVect.push_back("Romance");
    testVect.push_back("Musical");
    std::string year = "2005";
    int id = 3;
    string description = "Stop-animated musical fantasy.";
    string director = "Tim Burton";
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
    string title = "Coraline";
    int quantity = 5;
    std::vector<std::string> testVect;
    testVect.push_back("Horror");
    testVect.push_back("Fantasy");
    std::string year = "2009";
    int id = 42;
    string description = "American stop-motion animated dark fantasy film.";
    string director = "Tim Burton";
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

#endif //__DVD_TEST_HPP__
