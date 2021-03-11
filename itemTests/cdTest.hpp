#ifndef __CD_TEST_HPP__
#define __CD_TEST_HPP__

#include "gtest/gtest.h"
#include <gmock/gmock-matchers.h>

#include "cd.hpp"
#include <QString>
#include <QVector>

TEST(CdTest, posTracks)
{    //series of test values
    QString title = "One of the Boys";
    int quantity = 1;
    QVector<QString> testVect;
    testVect.push_back("Pop");
    QString year = "2008";
    int id = 23;
    QString description = "Katy Perry's first studio album.";
    QString artist = "Katy Perry";
    int tracks = 11;

   Cd cd(title, quantity, testVect, year, id, description, artist, tracks);
   EXPECT_EQ(cd.getTracks(), tracks);
}

TEST(CdTest, negTracks)
{ 
    //series of test values
    QString title = "One of the Boys";
    int quantity = 1;
    QVector<QString> testVect;
    testVect.push_back("Pop");
    QString year = "2008";
    int id = 23;
    QString description = "Katy Perry's first studio album.";
    QString artist = "Katy Perry";
    int tracks = -11;

   Cd cd(title, quantity, testVect, year, id, description, artist, tracks);
    EXPECT_EQ(cd.getTracks(), 0);
}

TEST(CdTest, constructor)
{ 
    //series of test values
    QString title = "Salad Days";
    int quantity = 3;
    QVector<QString> testVect;
    testVect.push_back("Indie Rock");
    testVect.push_back("Psychedelic pop");
    QString year = "2014";
    int id = 15;
    QString description = "Studio album by Mac DeMarco.";
    QString artist = "Mac DeMarco";
    int tracks = 11;

    Cd cd(title, quantity, testVect, year, id, description, artist, tracks);

    EXPECT_EQ(cd.getArtist(), artist);
    EXPECT_EQ(cd.getTracks(), tracks);
    EXPECT_EQ(cd.getDescription(), description);
}

TEST(CdTest, changeValue)
{ 
    //series of test values
    QString title = "Salad Days";
    int quantity = 3;
    QVector<QString> testVect;
    testVect.push_back("Indie Rock");
    testVect.push_back("Psychedelic pop");
    QString year = "2014";
    int id = 15;
    QString description = "Studio album by Mac DeMarco.";
    QString artist = "McBriare Samuel Lanyon";
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

TEST(CdTest, stringifyItem)
{ 
    //series of test values
    QString title = "Salad Days";
    int quantity = 3;
    QVector<QString> testVect;
    testVect.push_back("Indie Rock");
    testVect.push_back("Psychedelic pop");
    QString year = "2014";
    int id = 15;
    QString description = "Studio album by Mac DeMarco.";
    QString artist = "Mac DeMarco";
    int tracks = 11;

    Cd cd(title, quantity, testVect, year, id, description, artist, tracks);
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
    item += "\nArtist: "+artist+"\n";
    item += "Tracks: "+QString::number(tracks)+"\n";
    
    //EXPECT_EQ(cd.getArtist(), artist);
    //EXPECT_EQ(cd.getTracks(), tracks);
    EXPECT_EQ(cd.stringifyItem(), item);
}


TEST(CdTest, stringify2)
{ 
    //series of test values
    QString title = "Salad Days";
    int quantity = 3;
    QVector<QString> testVect;
    testVect.push_back("Indie Rock");
    testVect.push_back("Psychedelic pop");
    QString year = "2014";
    int id = 15;
    QString description = "Studio album by Mac DeMarco.";
    QString artist = "Mac DeMarco";
    int tracks = 11;

    LibraryItemComponent* cd = new Cd(title, quantity, testVect, year, id, description, artist, tracks);

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
    item += "\nArtist: "+artist+"\n";
    item += "Tracks: "+QString::number(tracks)+"\n";
    
    EXPECT_EQ(cd->stringifyItem(), item);


    delete cd;
}



#endif //__CD_TEST_HPP__
