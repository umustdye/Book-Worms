#include "../header/cd.hpp"

#include <string>
#include <algorithm>

using std::string;
using std::max;



Cd::Cd(std::string artist, int tracks, std::string title, int quantity, std::vector<std::string> genres, std::string year, int id, std::string description, int length)
    : LibraryItemComponent{title, quantity, genres, year, id, description, length}
{
    setArtist(artist);
    setTracks(tracks);
}


void Cd::setArtist(std::string artist)
{
    this->artist = artist;
}

std::string Cd::getArtist()
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
