#include "../header/book.hpp"

#include <string>

using std::string;

Book::Book()
{
    setAuthor("");
}

Book::Book(std::string author)
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
