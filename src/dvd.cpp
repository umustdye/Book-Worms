#include "../header/dvd.hpp"

#include <string>
#include <vector>
using std::string;
using std::vector;


Dvd::Dvd(std::string title, int quantity, std::vector<std::string> genres, std::string year, int id, std::string description, std::string director, int length)
    : LibraryItemComponent{title, quantity, genres, year, id, description}
{
    setDirector(director);
    setLength(length);
}

void Dvd::setDirector(std::string director)
{
    this->director = director;
}

std::string Dvd::getDirector()
{
    return this->director;
}

void Dvd::setLength(int length)
{
    this->length = length;
}

int Dvd::getLength()
{
    return this->length;
}
