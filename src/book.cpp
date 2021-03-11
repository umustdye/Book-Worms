#include "header/book.hpp"

Book::Book(QString title, int quantity, QVector<QString> genres, QString year, int id, QString description, QString author, int pages)
    : LibraryItemComponent(title, quantity, genres, year, id, description)
{
    setAuthor(author);
    setPages(pages);
}

Book::~Book()
{
}

void Book::setAuthor(QString author)
{
    this->author = author;
}

QString Book::getAuthor()
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

QString Book::stringifyItem()
{
    QString item = LibraryItemComponent::stringifyItem();
    item += "\nAuthor: "+ this->author+"\n";
    item += "Pages: "+QString::number(pages)+"\n";

    return item;
}
