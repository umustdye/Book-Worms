#include "../header/item.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;


void LibraryItemComponent::setTitle(std::string title)
{
    this->title = title;
}
        
std::string LibraryItemComponent::getTitle()
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

void LibraryItemComponent::setGenres(std::vector<std::string> genres)
{
    this->genres = genres;
}

void LibraryItemComponent::addGenre(std::string genre)
{
    this->genres.push_back(genre);
}

std::vector<std::string> LibraryItemComponent::getGenres()
{
    return this->genres;
}

void LibraryItemComponent::setYear(std::string year)
{
    this->year = year;
}

std::string LibraryItemComponent::getYear()
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

std::string LibraryItemComponent::stringifyItem()
{
    return "";
}

