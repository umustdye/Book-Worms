#ifndef LIBRARYITEMFACTORY_HPP
#define LIBRARYITEMFACTORY_HPP

#include "item.hpp"

enum Type {
    BookItem,
    CdItem,
    DvdItem
};

class LibraryItemFactory {
public:
    LibraryItemFactory();
    ~LibraryItemFactory();
    LibraryItemComponent* createItem(Type type, int id = -1);
};

#endif // LIBRARYITEMFACTORY_HPP
