#include "../header/cd.hpp"
#include <string>
#include <algorithm>

using std::string;
using std::max;



Cd::Cd(std::string title, int quantity, std::vector<std::string> genres, std::string year, int id, std::string description, std::string artist, int tracks)
    : LibraryItemComponent{title, quantity, genres, year, id, description}
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

string Cd::stringifyItem()
{
    string item = LibraryItemComponent::stringifyItem();
    item += "\nArtist: "+ this->artist+"\n";
    item += "Tracks: "+std::to_string(tracks)+"\n";
    return item;
}
