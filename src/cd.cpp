#include "cd.hpp"
#include <algorithm>

using std::max;


Cd::Cd(QString title, int quantity, QVector<QString> genres, QString year, int id, QString description, QString artist, int tracks)
    : LibraryItemComponent(title, quantity, genres, year, id, description)
{
    setArtist(artist);
    setTracks(tracks);
}

Cd::~Cd()
{
}

void Cd::setArtist(QString artist)
{
    this->artist = artist;
}

QString Cd::getArtist()
{
    return this->artist;
}

void Cd::setTracks(int tracks)
{
    this->tracks = max(0, tracks);
}

int Cd::getTracks()
{
    return this->tracks;
}

QString Cd::getCreatorStr() const
{
    return QString("Artist: %0").arg(this->artist);
}

QString Cd::getLengthStr() const
{
    return tracks == 1 ? QString("%0 Track").arg(tracks) : QString("%0 Tracks").arg(tracks);
}

QString Cd::getCreator()
{
    return this->artist;
}

int Cd::getLength()
{
    return this->tracks;
}

//QString Cd::stringifyItem()
//{
//    QString item = LibraryItemComponent::stringifyItem();
//    item += "\nArtist: "+ this->artist+"\n";
//    item += "Tracks: "+QString::number(tracks)+"\n";
//    return item;
//}
