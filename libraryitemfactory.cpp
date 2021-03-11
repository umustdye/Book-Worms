#include "libraryitemfactory.hpp"

LibraryItemFactory::LibraryItemFactory()
{
}

LibraryItemFactory::~LibraryItemFactory()
{
}

LibraryItemComponent *LibraryItemFactory::createItem(Type type, LibraryItemComponent *item)
{
    switch(type) {
    case BookItem: {
        BookDialog dialog;
        return dialog.create(dynamic_cast<Book *>(item));
    }
    case CdItem: {
        CdDialog dialog;
        return dialog.create(dynamic_cast<Cd *>(item));
    }
    case DvdItem: {
        DvdDialog dialog;
        return dialog.create(dynamic_cast<Dvd *>(item));
    }
    case CollectionItem: {
        CollectionDialog dialog;
        return dialog.create(dynamic_cast<LibraryItemCollection *>(item));
    }
    default: return nullptr;
    }
}
