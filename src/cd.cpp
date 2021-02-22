#include "../header/cd.hpp"

#include <string>
#include <algorithm>

using std::string;
using std::max;

Cd::Cd()
{
    setArtist("");
    setTracks(0);
}


Cd::Cd(std::string artist, int tracks)
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
