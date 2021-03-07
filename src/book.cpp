#include "../header/book.hpp"

#include <string>

using std::string;


Book::Book(std::string title, int quantity, std::vector<std::string> genres, std::string year, int id, std::string description, std::string author, int pages)
    : LibraryItemComponent{title, quantity, genres, year, id, description}
{
    setAuthor(author);
    setPages(pages);
}

void Book::setAuthor(std::string author)
{
    this->author = author;
}

std::string Book::getAuthor()
{
    return this->author;
}

void Book::setPages(int pages)
{
    this->pages = pages;
}

int Book::getPages()
{
    return this->pages;
}

string Book::stringifyItem()
{
    string item = LibraryItemComponent::stringifyItem();
    item += "\nAuthor: "+ this->author+"\n";
    item += "Pages: "+std::to_string(pages)+"\n";
    return item;
}
