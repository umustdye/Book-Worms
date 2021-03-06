#include "libraryitemfactory.hpp"

LibraryItemFactory::LibraryItemFactory()
{
}

LibraryItemFactory::~LibraryItemFactory()
{
}

LibraryItemComponent *LibraryItemFactory::createItem(Type type, int id)
{
    switch(type) {
    case BookItem: {
        BookDialog dialog;
        return dialog.create(id);
    }
    case CdItem: {
        CdDialog dialog;
        return dialog.create(id);
    }
    case DvdItem: {
        DvdDialog dialog;
        return dialog.create(id);
    }
    case CollectionItem: {
        CollectionDialog dialog;
        return dialog.create(id);
    }
    default: return nullptr;
    }
}
