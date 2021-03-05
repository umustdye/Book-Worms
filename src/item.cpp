#include "../header/item.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;


LibraryItemComponent::LibraryItemComponent(std::string title, int quantity, std::vector<std::string> genres, std::string year, int id, std::string description)
{
    setTitle(title);
    setQuantity(quantity);
    setGenres(genres);
    setYear(year);
    setId(id);
    setDescription(description);

}

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

void LibraryItemComponent::setDescription(std::string description)
{
    this->description = description;
}

std::string LibraryItemComponent::getDescription()
{
    return this->description;
}

std::string LibraryItemComponent::stringifyItem()
{
    string item = "";
    item = "Title: "+this->title+"\n";
    item += "Item ID: "+std::to_string(this->id)+"\n";
    item += "Year: "+this->year+"\n";
    item += "Genres: ";
    for(auto genre:genres)
    {
        item += genre + " ";   
    }
    item += "\nDescription: "+this->description+"\n";
    item += "Quantity: "+std::to_string(this->quantity);
    return item;
}

