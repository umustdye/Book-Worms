#include "../header/dvd.hpp"

#include <string>

using std::string;

Dvd::Dvd()
{
    setDirector("");
}

Dvd::Dvd(std::string director)
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
