#ifndef __CD_TEST_HPP__
#define __CD_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/cd.hpp"

TEST(CdTest, posTracks)
{    //series of test values
    string title = "One of the Boys";
    int quantity = 1;
    std::vector<std::string> testVect;
    testVect.push_back("Pop");
    std::string year = "2008";
    int id = 23;
    string description = "Katy Perry's first studio album.";
    string artist = "Katy Perry";
    int tracks = 11;

   Cd cd(title, quantity, testVect, year, id, description, artist, tracks);
   EXPECT_EQ(cd.getTracks(), tracks);
}

TEST(CdTest, negTracks)
{ 
    //series of test values
    string title = "One of the Boys";
    int quantity = 1;
    std::vector<std::string> testVect;
    testVect.push_back("Pop");
    std::string year = "2008";
    int id = 23;
    string description = "Katy Perry's first studio album.";
    string artist = "Katy Perry";
    int tracks = -11;

   Cd cd(title, quantity, testVect, year, id, description, artist, tracks);
    EXPECT_EQ(cd.getTracks(), 0);
}

TEST(CdTest, constructor)
{ 
    //series of test values
    string title = "Salad Days";
    int quantity = 3;
    std::vector<std::string> testVect;
    testVect.push_back("Indie Rock");
    testVect.push_back("Psychedelic pop");
    std::string year = "2014";
    int id = 15;
    string description = "Studio album by Mac DeMarco.";
    string artist = "Mac DeMarco";
    int tracks = 11;

    Cd cd(title, quantity, testVect, year, id, description, artist, tracks);

    EXPECT_EQ(cd.getArtist(), artist);
    EXPECT_EQ(cd.getTracks(), tracks);
    EXPECT_EQ(cd.getDescription(), description);
}

TEST(CdTest, changeValue)
{ 
    //series of test values
    string title = "Salad Days";
    int quantity = 3;
    std::vector<std::string> testVect;
    testVect.push_back("Indie Rock");
    testVect.push_back("Psychedelic pop");
    std::string year = "2014";
    int id = 15;
    string description = "Studio album by Mac DeMarco.";
    string artist = "McBriare Samuel Lanyon";
    int tracks = 13;

    Cd cd(title, quantity, testVect, year, id, description, artist, tracks);
    EXPECT_EQ(cd.getArtist(), artist);
    EXPECT_EQ(cd.getTracks(), tracks);
    artist = "Mac DeMarco";
    tracks = 11;
    cd.setArtist(artist);
    cd.setTracks(tracks);
    EXPECT_EQ(cd.getArtist(), artist);
    EXPECT_EQ(cd.getTracks(), tracks);
}
#endif //__CD_TEST_HPP__
