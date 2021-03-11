#include "collection.hpp"


LibraryItemCollection::LibraryItemCollection(QString title, int quantity, QVector<QString> genres, QString year, int id, QString description, QVector<LibraryItemComponent*> children)
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

void LibraryItemCollection::setChildren(QVector<LibraryItemComponent*> children)
{
    this->children = children;
}
        
QVector<LibraryItemComponent*> LibraryItemCollection::getChildren()
{
    return this->children;
}

QString LibraryItemCollection::stringifyItem()
{
    QString item = LibraryItemComponent::stringifyItem();
    for(auto child : children)
    {
        item += "\n\t" + child->stringifyItem();
    }
    return item;
}
