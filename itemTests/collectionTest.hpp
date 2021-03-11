#ifndef __COLLECTION_TEST_HPP__
#define __COLLECTION_TEST_HPP__

#include "gtest/gtest.h"
#include <gmock/gmock-matchers.h>
#include "collection.hpp"
#include "item.hpp"
#include "book.hpp"
#include "cd.hpp"
#include "dvd.hpp"
#include <QVector>
#include <QString>



TEST(CollectionTest, emptyConstructor)
{
    LibraryItemCollection collection;
    EXPECT_EQ(collection.getId(), -1);
    EXPECT_EQ(collection.getTitle(), "");
    QVector<LibraryItemComponent*> testItems = collection.getChildren();
    for(auto item:testItems)
    {
        EXPECT_EQ(item->getTitle(), "");   
    }
    EXPECT_EQ(collection.getDescription(), "");
    EXPECT_EQ(collection.getYear(), "");
    EXPECT_EQ(collection.getQuantity(), 0);

}

TEST(CollectionTest, constructorBook)
{
    QString author = "Suzanne Collins";
    
    QString title1 = "The Hunger Games";
    QString title2 = "Catching Fire";
    QString title3 = "Mockingjay";
    int id = 23;
    QString year1 = "2008";
    QString year2 = "2009";
    QString year3 = "2010";
    int quantity = 2;
    QVector<QString> genres;
    genres.push_back("Science Fiction");
    genres.push_back("Thriller");
    genres.push_back("Suspense");
    QString description1 = "First book of series";
    QString description2 = "Second book of the series";
    QString description3 = "Third book of the series";
    int pages1 = 374;
    int pages2 = 391;
    int pages3 = 390;
    LibraryItemComponent* book1 = new Book(title1, quantity, genres, year1, id, description1, author, pages1);
    LibraryItemComponent* book2 = new Book(title2, quantity, genres, year2, id, description2, author, pages2);
    LibraryItemComponent* book3 = new Book(title3, quantity, genres, year3, id, description3, author, pages3);
    QVector<LibraryItemComponent*> items;
    items.push_back(book1);
    items.push_back(book2);
    items.push_back(book3);

    QString title = "The Hunger Games";
    QString description = "The Hunger Games trilogy";
    LibraryItemCollection collection(title, quantity, genres, year1, id, description, items);

    EXPECT_EQ(collection.getTitle(), title);
    EXPECT_EQ(collection.getQuantity(), quantity);
    EXPECT_EQ(collection.getGenres(), genres);
    EXPECT_EQ(collection.getYear(), year1);
    EXPECT_EQ(collection.getId(), id);
    EXPECT_EQ(collection.getDescription(), description);
    //Test the individual items
    QVector<LibraryItemComponent*> testItems = collection.getChildren();
    EXPECT_EQ(testItems[0]->getTitle(), title1);
    EXPECT_EQ(testItems[1]->getTitle(), title2);
    EXPECT_EQ(testItems[2]->getTitle(), title3);
    EXPECT_EQ(testItems[0]->getYear(), year1);
    EXPECT_EQ(testItems[1]->getYear(), year2);
    EXPECT_EQ(testItems[2]->getYear(), year3);

}


TEST(CollectionTest, constructorDvd)
{
    QString director = "Peter Jackson";
    
    QString title1 = "The Fellowship of the Ring";
    QString title2 = "The Two Towers";
    QString title3 = "The Return of the King";
    int id = 23;
    QString year1 = "2001";
    QString year2 = "2002";
    QString year3 = "2003";
    int quantity = 1;
    QVector<QString> genres;
    genres.push_back("Fantasy Fiction");
    genres.push_back("Chivalric Romance");
    QString description1 = "First movie of series";
    QString description2 = "Second movie of the series";
    QString description3 = "Third movie of the series";
    int length1 = 178;
    int length2 = 179;
    int length3 = 201;
    LibraryItemComponent* dvd1 = new Dvd(title1, quantity, genres, year1, id, description1, director, length1);
    LibraryItemComponent* dvd2 = new Dvd(title2, quantity, genres, year2, id, description2, director, length2);
    LibraryItemComponent* dvd3 = new Dvd(title3, quantity, genres, year3, id, description3, director, length3);
    QVector<LibraryItemComponent*> items;
    items.push_back(dvd1);
    items.push_back(dvd2);
    items.push_back(dvd3);

    QString title = "The Lord of the Rings";
    QString description = "The Lord of the Rings trilogy";
    LibraryItemCollection collection(title, quantity, genres, year1, id, description, items);

    EXPECT_EQ(collection.getTitle(), title);
    EXPECT_EQ(collection.getQuantity(), quantity);
    EXPECT_EQ(collection.getGenres(), genres);
    EXPECT_EQ(collection.getYear(), year1);
    EXPECT_EQ(collection.getId(), id);
    EXPECT_EQ(collection.getDescription(), description);
    //Test the individual items
    QVector<LibraryItemComponent*> testItems = collection.getChildren();
    EXPECT_EQ(testItems[0]->getTitle(), title1);
    EXPECT_EQ(testItems[1]->getTitle(), title2);
    EXPECT_EQ(testItems[2]->getTitle(), title3);
    EXPECT_EQ(testItems[0]->getYear(), year1);
    EXPECT_EQ(testItems[1]->getYear(), year2);
    EXPECT_EQ(testItems[2]->getYear(), year3);

}

TEST(CollectionTest, constructorCd)
{
    QString artist = "Hannah Montana";
    
    QString title1 = "Hannah Montana";
    QString title2 = "Hannah Montana2";
    QString title3 = "Hannah Montana3";
    int id = 23;
    QString year1 = "2006";
    QString year2 = "2007";
    QString year3 = "2009";
    int quantity = 1;
    QVector<QString> genres;
    genres.push_back("Pop");
    genres.push_back("Teen Pop");
    genres.push_back("Suspense");
    QString description1 = "First cd of series";
    QString description2 = "Second cd of the series";
    QString description3 = "Third cd of the series";
    int tracks1 = 10;
    int tracks2 = 11;
    int tracks3 = 10;
    LibraryItemComponent* cd1 = new Cd(title1, quantity, genres, year1, id, description1, artist, tracks1);
    LibraryItemComponent* cd2 = new Cd(title2, quantity, genres, year2, id, description2, artist, tracks2);
    LibraryItemComponent* cd3 = new Cd(title3, quantity, genres, year3, id, description3, artist, tracks3);
    QVector<LibraryItemComponent*> items;
    items.push_back(cd1);
    items.push_back(cd2);
    items.push_back(cd3);

    QString title = "Hannah Montana Tv Soundtrack";
    QString description = "Songs from the Hannah Montana television series";
    LibraryItemCollection collection(title, quantity, genres, year1, id, description, items);

    EXPECT_EQ(collection.getTitle(), title);
    EXPECT_EQ(collection.getQuantity(), quantity);
    EXPECT_EQ(collection.getGenres(), genres);
    EXPECT_EQ(collection.getYear(), year1);
    EXPECT_EQ(collection.getId(), id);
    EXPECT_EQ(collection.getDescription(), description);
    QString item = "";
    item = "Title: "+title+"\n";
    item += "Item ID: "+QString::number(id)+"\n";
    item += "Year: "+year1+"\n";
    item += "Genres: ";
    for(auto genre:genres)
    {
        item += genre + " ";   
    }
    item += "\nDescription: "+description+"\n";
    item += "Quantity: "+QString::number(quantity);
    
    //item one
    item += "\n\tTitle: "+title1+"\n";
    item += "Item ID: "+QString::number(id)+"\n";
    item += "Year: "+year1+"\n";
    item += "Genres: ";
    for(auto genre:genres)
    {
        item += genre + " ";   
    }
    item += "\nDescription: "+description1+"\n";
    item += "Quantity: "+QString::number(quantity);
    item += "\nArtist: "+artist+"\n";
    item += "Tracks: "+QString::number(tracks1)+"\n";


    //item 2
    item += "\n\tTitle: "+title2+"\n";
    item += "Item ID: "+QString::number(id)+"\n";
    item += "Year: "+year2+"\n";
    item += "Genres: ";
    for(auto genre:genres)
    {
        item += genre + " ";   
    }
    item += "\nDescription: "+description2+"\n";
    item += "Quantity: "+QString::number(quantity);
    item += "\nArtist: "+artist+"\n";
    item += "Tracks: "+QString::number(tracks2)+"\n";

    //item 3
    item += "\n\tTitle: "+title3+"\n";
    item += "Item ID: "+QString::number(id)+"\n";
    item += "Year: "+year3+"\n";
    item += "Genres: ";
    for(auto genre:genres)
    {
        item += genre + " ";   
    }
    item += "\nDescription: "+description3+"\n";
    item += "Quantity: "+QString::number(quantity);
    item += "\nArtist: "+artist+"\n";
    item += "Tracks: "+QString::number(tracks3)+"\n";

    EXPECT_EQ(collection.stringifyItem(), item);



    //Test the individual items
    QVector<LibraryItemComponent*> testItems = collection.getChildren();
    EXPECT_EQ(testItems[0]->getTitle(), title1);
    EXPECT_EQ(testItems[1]->getTitle(), title2);
    EXPECT_EQ(testItems[2]->getTitle(), title3);
    EXPECT_EQ(testItems[0]->getYear(), year1);
    EXPECT_EQ(testItems[1]->getYear(), year2);
    EXPECT_EQ(testItems[2]->getYear(), year3);

}

#endif //__COLLECTION_TEST_HPP__
