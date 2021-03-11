#ifndef LIBRARYITEMMODEL_H
#define LIBRARYITEMMODEL_H

#include <QAbstractTableModel>
#include "item.hpp"

class LibraryItemModel : public QAbstractTableModel
{
    Q_OBJECT

private:
    QVector<LibraryItemComponent *> *items;
    const int COLS = 7;

public:
    explicit LibraryItemModel(QVector<LibraryItemComponent *> *items, QObject *parent = nullptr);
    ~LibraryItemModel();
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void addItem(LibraryItemComponent *item);
    void updateItems(QModelIndexList list);
    void removeItems(QVector<int> &rows);
};

#endif // LIBRARYITEMMODEL_H
