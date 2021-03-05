#ifndef __COLLECTION_HPP__
#define __COLLECTION_HPP__

#include "item.hpp"
#include <vector>
#include <string>

using std::vector;
using std::string;

class LibraryItemCollection : public LibraryItemComponent
{
    private:
        vector <LibraryItemComponent*> children;

    public:
        LibraryItemCollection(string title="", int quantity=0, vector<string> genres = vector<string>(), string year="", int id = -1, string description="", vector<LibraryItemComponent*> children = vector<LibraryItemComponent*>());
        ~LibraryItemCollection();
        void addChild(LibraryItemComponent* child);
        void removeChild(int index);
        LibraryItemComponent* getChild(int index);
        void setChildren(vector<LibraryItemComponent*> children);
        vector<LibraryItemComponent*> getChildren();
        virtual string stringifyItem() override;

};

#endif //__COLLECTION_HPP__

