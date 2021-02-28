#include "../header/dvd.hpp"

#include <string>
#include <vector>
using std::string;
using std::vector;


Dvd::Dvd(std::string director, std::string title, int quantity, std::vector<std::string> genres, std::string year, int id, std::string description, int length)
    : LibraryItemComponent{title, quantity, genres, year, id, description, length}
{
    setDirector(director);
}

void Dvd::setDirector(std::string director)
{
    this->director = director;
}

std::string Dvd::getDirector()
{
    return this->director;
}
