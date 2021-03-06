#include "libraryitemfactory.hpp"
#include "bookdialog.hpp"
#include "cddialog.hpp"
#include "dvddialog.hpp"

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
        BookDialog fac;
        return fac.create(id);
    }
    case CdItem: {
        CdDialog fac;
        return fac.create(id);
    }
    case DvdItem: {
        DvdDialog fac;
        return fac.create(id);
    }
    default: return nullptr;
    }
}
