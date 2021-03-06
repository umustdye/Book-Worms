#include "../header/collection.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;


LibraryItemCollection::LibraryItemCollection(string title, int quantity, vector<string> genres, string year, int id, string description, vector<LibraryItemComponent*> children)
    : LibraryItemComponent{title, quantity, genres, year, id, description}
{
    setChildren(children);
}

LibraryItemCollection::~LibraryItemCollection()
{
    for(auto child:children)
    {
        delete child;
    }
}

void LibraryItemCollection::addChild(LibraryItemComponent* child)
{
   this->children.push_back(child);
}
        
void LibraryItemCollection::removeChild(int index)
{
    this->children.erase(this->children.begin() + index);   
}
        
LibraryItemComponent* LibraryItemCollection::getChild(int index)
{
    return this->children[index];
}

void LibraryItemCollection::setChildren(vector<LibraryItemComponent*> children)
{
    this->children = children;
}
        
vector<LibraryItemComponent*> LibraryItemCollection::getChildren()
{
    return this->children;
}

string LibraryItemCollection::stringifyItem()
{
    string item = LibraryItemComponent::stringifyItem();
    for(auto child : children)
    {
        item += "\n\t" + child->stringifyItem();
    }
    return item;
}
