#ifndef __COLLECTION_TEST_HPP__
#define __COLLECTION_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/collection.hpp"
#include "../header/item.hpp"
#include "../header/book.hpp"
#include "../header/cd.hpp"
#include "../header/dvd.hpp"
#include <vector>
#include <string>

using std::vector;
using std::string;

TEST(CollectionTest, emptyConstructor)
{
    LibraryItemCollection collection;
    EXPECT_EQ(collection.getId(), -1);
    EXPECT_EQ(collection.getTitle(), "");
    vector<LibraryItemComponent*> testItems = collection.getChildren();
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
    string author = "Suzanne Collins";
    
    string title1 = "The Hunger Games";
    string title2 = "Catching Fire";
    string title3 = "Mockingjay";
    int id = 23;
    string year1 = "2008";
    string year2 = "2009";
    string year3 = "2010";
    int quantity = 2;
    vector<string> genres;
    genres.push_back("Science Fiction");
    genres.push_back("Thriller");
    genres.push_back("Suspense");
    string description1 = "First book of series";
    string description2 = "Second book of the series";
    string description3 = "Third book of the series";
    int pages1 = 374;
    int pages2 = 391;
    int pages3 = 390;
    LibraryItemComponent* book1 = new Book(title1, quantity, genres, year1, id, description1, author, pages1);
    LibraryItemComponent* book2 = new Book(title2, quantity, genres, year2, id, description2, author, pages2);
    LibraryItemComponent* book3 = new Book(title3, quantity, genres, year3, id, description3, author, pages3);
    vector<LibraryItemComponent*> items;
    items.push_back(book1);
    items.push_back(book2);
    items.push_back(book3);

    string title = "The Hunger Games";
    string description = "The Hunger Games trilogy";
    LibraryItemCollection collection(title, quantity, genres, year1, id, description, items);

    EXPECT_EQ(collection.getTitle(), title);
    EXPECT_EQ(collection.getQuantity(), quantity);
    EXPECT_EQ(collection.getGenres(), genres);
    EXPECT_EQ(collection.getYear(), year1);
    EXPECT_EQ(collection.getId(), id);
    EXPECT_EQ(collection.getDescription(), description);
    //Test the individual items
    vector<LibraryItemComponent*> testItems = collection.getChildren();
    EXPECT_EQ(testItems[0]->getTitle(), title1);
    EXPECT_EQ(testItems[1]->getTitle(), title2);
    EXPECT_EQ(testItems[2]->getTitle(), title3);
    EXPECT_EQ(testItems[0]->getYear(), year1);
    EXPECT_EQ(testItems[1]->getYear(), year2);
    EXPECT_EQ(testItems[2]->getYear(), year3);

}


TEST(CollectionTest, constructorDvd)
{
    string director = "Peter Jackson";
    
    string title1 = "The Fellowship of the Ring";
    string title2 = "The Two Towers";
    string title3 = "The Return of the King";
    int id = 23;
    string year1 = "2001";
    string year2 = "2002";
    string year3 = "2003";
    int quantity = 1;
    vector<string> genres;
    genres.push_back("Fantasy Fiction");
    genres.push_back("Chivalric Romance");
    string description1 = "First movie of series";
    string description2 = "Second movie of the series";
    string description3 = "Third movie of the series";
    int length1 = 178;
    int length2 = 179;
    int length3 = 201;
    LibraryItemComponent* dvd1 = new Dvd(title1, quantity, genres, year1, id, description1, director, length1);
    LibraryItemComponent* dvd2 = new Dvd(title2, quantity, genres, year2, id, description2, director, length2);
    LibraryItemComponent* dvd3 = new Dvd(title3, quantity, genres, year3, id, description3, director, length3);
    vector<LibraryItemComponent*> items;
    items.push_back(dvd1);
    items.push_back(dvd2);
    items.push_back(dvd3);

    string title = "The Lord of the Rings";
    string description = "The Lord of the Rings trilogy";
    LibraryItemCollection collection(title, quantity, genres, year1, id, description, items);

    EXPECT_EQ(collection.getTitle(), title);
    EXPECT_EQ(collection.getQuantity(), quantity);
    EXPECT_EQ(collection.getGenres(), genres);
    EXPECT_EQ(collection.getYear(), year1);
    EXPECT_EQ(collection.getId(), id);
    EXPECT_EQ(collection.getDescription(), description);
    //Test the individual items
    vector<LibraryItemComponent*> testItems = collection.getChildren();
    EXPECT_EQ(testItems[0]->getTitle(), title1);
    EXPECT_EQ(testItems[1]->getTitle(), title2);
    EXPECT_EQ(testItems[2]->getTitle(), title3);
    EXPECT_EQ(testItems[0]->getYear(), year1);
    EXPECT_EQ(testItems[1]->getYear(), year2);
    EXPECT_EQ(testItems[2]->getYear(), year3);

}

TEST(CollectionTest, constructorCd)
{
    string artist = "Hannah Montana";
    
    string title1 = "Hannah Montana";
    string title2 = "Hannah Montana2";
    string title3 = "Hannah Montana3";
    int id = 23;
    string year1 = "2006";
    string year2 = "2007";
    string year3 = "2009";
    int quantity = 1;
    vector<string> genres;
    genres.push_back("Pop");
    genres.push_back("Teen Pop");
    genres.push_back("Suspense");
    string description1 = "First cd of series";
    string description2 = "Second cd of the series";
    string description3 = "Third cd of the series";
    int tracks1 = 10;
    int tracks2 = 11;
    int tracks3 = 10;
    LibraryItemComponent* cd1 = new Cd(title1, quantity, genres, year1, id, description1, artist, tracks1);
    LibraryItemComponent* cd2 = new Cd(title2, quantity, genres, year2, id, description2, artist, tracks2);
    LibraryItemComponent* cd3 = new Cd(title3, quantity, genres, year3, id, description3, artist, tracks3);
    vector<LibraryItemComponent*> items;
    items.push_back(cd1);
    items.push_back(cd2);
    items.push_back(cd3);

    string title = "Hannah Montana Tv Soundtrack";
    string description = "Songs from the Hannah Montana television series";
    LibraryItemCollection collection(title, quantity, genres, year1, id, description, items);

    EXPECT_EQ(collection.getTitle(), title);
    EXPECT_EQ(collection.getQuantity(), quantity);
    EXPECT_EQ(collection.getGenres(), genres);
    EXPECT_EQ(collection.getYear(), year1);
    EXPECT_EQ(collection.getId(), id);
    EXPECT_EQ(collection.getDescription(), description);
    string item = "";
    item = "Title: "+title+"\n";
    item += "Item ID: "+std::to_string(id)+"\n";
    item += "Year: "+year1+"\n";
    item += "Genres: ";
    for(auto genre:genres)
    {
        item += genre + " ";   
    }
    item += "\nDescription: "+description+"\n";
    item += "Quantity: "+std::to_string(quantity);
    
    //item one
    item += "\n\tTitle: "+title1+"\n";
    item += "Item ID: "+std::to_string(id)+"\n";
    item += "Year: "+year1+"\n";
    item += "Genres: ";
    for(auto genre:genres)
    {
        item += genre + " ";   
    }
    item += "\nDescription: "+description1+"\n";
    item += "Quantity: "+std::to_string(quantity);
    item += "\nArtist: "+artist+"\n";
    item += "Tracks: "+std::to_string(tracks1)+"\n";


    //item 2
    item += "\n\tTitle: "+title2+"\n";
    item += "Item ID: "+std::to_string(id)+"\n";
    item += "Year: "+year2+"\n";
    item += "Genres: ";
    for(auto genre:genres)
    {
        item += genre + " ";   
    }
    item += "\nDescription: "+description2+"\n";
    item += "Quantity: "+std::to_string(quantity);
    item += "\nArtist: "+artist+"\n";
    item += "Tracks: "+std::to_string(tracks2)+"\n";

    //item 3
    item += "\n\tTitle: "+title3+"\n";
    item += "Item ID: "+std::to_string(id)+"\n";
    item += "Year: "+year3+"\n";
    item += "Genres: ";
    for(auto genre:genres)
    {
        item += genre + " ";   
    }
    item += "\nDescription: "+description3+"\n";
    item += "Quantity: "+std::to_string(quantity);
    item += "\nArtist: "+artist+"\n";
    item += "Tracks: "+std::to_string(tracks3)+"\n";

    EXPECT_EQ(collection.stringifyItem(), item);



    //Test the individual items
    vector<LibraryItemComponent*> testItems = collection.getChildren();
    EXPECT_EQ(testItems[0]->getTitle(), title1);
    EXPECT_EQ(testItems[1]->getTitle(), title2);
    EXPECT_EQ(testItems[2]->getTitle(), title3);
    EXPECT_EQ(testItems[0]->getYear(), year1);
    EXPECT_EQ(testItems[1]->getYear(), year2);
    EXPECT_EQ(testItems[2]->getYear(), year3);

}

#endif //__COLLECTION_TEST_HPP__
