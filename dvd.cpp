#include "dvd.hpp"

Dvd::Dvd(QString title, int quantity, QVector<QString> genres, QString year, int id, QString description, QString director, int length)
    : LibraryItemComponent(title, quantity, genres, year, id, description)
{
    setDirector(director);
    setLength(length);
}

Dvd::~Dvd()
{
}

void Dvd::setDirector(QString director)
{
    this->director = director;
}

QString Dvd::getDirector()
{
    return this->director;
}

void Dvd::setLength(int length)
{
    this->length = length;
}

int Dvd::getLengthStr()
{
    return this->length;
}

QString Dvd::getCreatorStr() const
{
    return QString("Director: %0").arg(this->director);
}

QString Dvd::getLengthStr() const
{
    return length == 1 ? QString("%0 Minute").arg(length) : QString("%0 Minutes").arg(length);
}

QString Dvd::getCreator()
{
    return this->director;
}

int Dvd::getLength()
{
    return this->length;
}

//QString Dvd::stringifyItem()
//{
//    QString item = LibraryItemComponent::stringifyItem();
//    item += "\nDirector: "+ this->director+"\n";
//    item += "Length: "+QString::number(length)+" minutes\n";
//    return item;
//}
