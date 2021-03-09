#include "item.hpp"

LibraryItemComponent::LibraryItemComponent(QString title, int quantity, QVector<QString> genres, QString year, int id, QString description)
{
    setTitle(title);
    setQuantity(quantity);
    setGenres(genres);
    setYear(year);
    setId(id);
    setDescription(description);
}

LibraryItemComponent::~LibraryItemComponent()
{
}

void LibraryItemComponent::setTitle(QString title)
{
    this->title = title;
}

QString LibraryItemComponent::getTitle()
{
    return this->title;
}

void LibraryItemComponent::setQuantity(int quantity)
{
    this->quantity = quantity;
}

int LibraryItemComponent::getQuantity()
{
    return this->quantity;
}

void LibraryItemComponent::setGenres(QVector<QString> genres)
{
    this->genres = genres;
}

void LibraryItemComponent::addGenre(QString genre)
{
    this->genres.push_back(genre);
}

QVector<QString> LibraryItemComponent::getGenres()
{
    return this->genres;
}

void LibraryItemComponent::setYear(QString year)
{
    this->year = year;
}

QString LibraryItemComponent::getYear()
{
    return this->year;
}

void LibraryItemComponent::setId(int id)
{
    this->id = id;
}

int LibraryItemComponent::getId()
{
    return this->id;
}

void LibraryItemComponent::setDescription(QString description)
{
    this->description = description;
}

QString LibraryItemComponent::getDescription()
{
    return this->description;
}

QString LibraryItemComponent::stringifyItem()
{
    QString item = "";
    item = "Title: "+this->title+"\n";
    item += "Item ID: "+QString::number(this->id)+"\n";
    item += "Year: "+this->year+"\n";
    item += "Genres: ";
    for(QString &genre : genres)
    {
        item += genre + " ";
    }
    item += "\nDescription: "+this->description+"\n";
    item += "Quantity: "+QString::number(this->quantity);

    return item;
}

