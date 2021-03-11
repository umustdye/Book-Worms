#ifndef LIBRARYITEMPROXYMODEL_H
#define LIBRARYITEMPROXYMODEL_H

#include <QSortFilterProxyModel>

class LibraryItemProxyModel : public QSortFilterProxyModel
{
private:
    bool filterBook;
    bool filterCd;
    bool filterDvd;
    bool filterCollection;

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
    bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const override;

public:
    LibraryItemProxyModel(QObject *parent = nullptr);
    void toggleFilterBook();
    void toggleFilterCd();
    void toggleFilterDvd();
    void toggleFilterCollection();

};

#endif // LIBRARYITEMPROXYMODEL_H
