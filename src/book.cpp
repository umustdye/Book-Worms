#include "../header/book.hpp"

#include <string>

using std::string;


Book::Book(std::string author, std::string title, int quantity, std::vector<std::string> genres, std::string year, int id, std::string description, int length)
    : LibraryItemComponent{title, quantity, genres, year, id, description, length}
{
    setAuthor(author);
}

void Book::setAuthor(std::string author)
{
    this->author = author;
}

std::string Book::getAuthor()
{
    return this->author;
}
