#include "collection.hpp"


LibraryItemCollection::LibraryItemCollection(QString title, int quantity, QVector<QString> genres, QString year, int id, QString description, QVector<LibraryItemComponent*> children, QString creator)
    : LibraryItemComponent(title, quantity, genres, year, id, description), creator(creator)
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

QString LibraryItemCollection::getCreator() const
{
    return QString("Creator: %0").arg(this->creator);
}

QString LibraryItemCollection::getLength() const
{
    return children.size() == 1 ? QString("%0 Items").arg(children.size()) : QString("%0 Item").arg(children.size());
}

QString LibraryItemCollection::getDescription()
{
    QString desc = LibraryItemComponent::getDescription();
    desc += "\tContains: ";

    for(int i = 0; i < children.size(); ++i) {
        desc += children[i]->getTitle();
        if(i < children.size() - 1) desc += ", ";
    }

    return desc;
}

//QString LibraryItemCollection::stringifyItem()
//{
//    QString item = LibraryItemComponent::stringifyItem();
//    for(auto child : children)
//    {
//        item += "\n\t" + child->stringifyItem();
//    }
//    return item;
//}
