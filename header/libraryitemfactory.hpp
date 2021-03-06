#ifndef LIBRARYITEMFACTORY_HPP
#define LIBRARYITEMFACTORY_HPP

#include "item.hpp"
#include "bookdialog.hpp"
#include "cddialog.hpp"
#include "dvddialog.hpp"
#include "collectiondialog.hpp"

enum Type {
    BookItem,
    CdItem,
    DvdItem,
    CollectionItem
};

class LibraryItemFactory {
public:
    LibraryItemFactory();
    ~LibraryItemFactory();
    LibraryItemComponent* createItem(Type type, int id = -1);
};

#endif // LIBRARYITEMFACTORY_HPP
