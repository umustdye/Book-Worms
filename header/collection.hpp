#ifndef __COLLECTION_HPP__
#define __COLLECTION_HPP__

#include "item.hpp"
#include <vector>

using std::vector;

class LibraryItemCollection : public LibraryItemComponent
{
    private:
        std::vector <LibraryItemComponent> children;

    public:
        LibraryItemCollection();
        LibraryItemCollection(std::vector<LibraryItemComponent> children);
        void addChild(LibraryItemComponent child);
        void removeChild(int index);
        LibraryItemComponent getChild(int index);
        std::vector<LibraryItemComponent> getChildren();
}

#endif //__COLLECTION_HPP__

