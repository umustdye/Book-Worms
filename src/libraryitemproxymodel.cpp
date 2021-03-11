#include "libraryitemproxymodel.hpp"

LibraryItemProxyModel::LibraryItemProxyModel(QObject *parent) : QSortFilterProxyModel(parent),
    filterBook(true), filterCd(true), filterDvd(true), filterCollection(true)
{
    this->setFilterCaseSensitivity(Qt::CaseInsensitive);
    this->setSortCaseSensitivity(Qt::CaseInsensitive);
}

void LibraryItemProxyModel::toggleFilterBook()
{
    filterBook = !filterBook;
    this->invalidateFilter();
}

void LibraryItemProxyModel::toggleFilterCd()
{
    filterCd = !filterCd;
    this->invalidateFilter();
}

void LibraryItemProxyModel::toggleFilterDvd()
{
    filterDvd = !filterDvd;
    this->invalidateFilter();
}

void LibraryItemProxyModel::toggleFilterCollection()
{
    filterCollection = !filterCollection;
    this->invalidateFilter();
}

bool LibraryItemProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    bool accept = false;
    QString type = this->sourceModel()->data(this->sourceModel()->index(source_row, 0, source_parent), 55).toString();
    QString title = this->sourceModel()->data(this->sourceModel()->index(source_row, 0, source_parent)).toString();

    //Filter based on type
    if(filterBook && type == "Book") {
        accept = true;
    } else if(filterCd && type == "Cd") {
        accept = true;
    }  else if(filterDvd && type == "Dvd") {
        accept = true;
    }  else if(filterCollection && type == "LibraryItemCollection") {
        accept = true;
    }

    //If does not match regex, excluse
    if(!title.contains(filterRegularExpression())) {
        accept = false;
    }

    return accept;
}

bool LibraryItemProxyModel::lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const
{
    QString left = sourceModel()->data(source_left).toString();
    QString right = sourceModel()->data(source_right).toString();
    return left < right;
}
