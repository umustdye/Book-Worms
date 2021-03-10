#include "libraryitemmodel.hpp"
#include "libraryitemfactory.hpp"
#include "book.hpp"

LibraryItemModel::LibraryItemModel(QVector<LibraryItemComponent *> *items, QObject *parent)
    : QAbstractTableModel(parent), items(items)
{
}

LibraryItemModel::~LibraryItemModel()
{
}

QVariant LibraryItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole) return QVariant();

    if(orientation == Qt::Horizontal) {
        switch(section) {
        case 0 : return QString("Title");
        case 1 : return QString("Quantity");
        case 2 : return QString("Creator");
        case 3 : return QString("Year");
        case 4 : return QString("Length");
        case 5 : return QString("Description");
        case 6 : return QString("Genres");
        default: return QString("DEFAULT");
        }
    } else {
        return QString::number(section + 1);
    }
}

int LibraryItemModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return items->size();
}

int LibraryItemModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return COLS;
}

QVariant LibraryItemModel::data(const QModelIndex &index, int role) const
{
    int section = index.column();
    LibraryItemComponent *item = items->at(index.row());
    if(role == Qt::DisplayRole || role == Qt::EditRole) {
        switch(section) {
        case 0 : return item->getTitle();
        case 1 : return item->getQuantity();
        case 2 : return item->getCreator();
        case 3 : return item->getYear();
        case 4 : return item->getLength();
        case 5 : return item->getDescription();
        case 6 : {
            QString genres;
            for(int i = 0; i < item->getGenres().size(); ++i) {
                genres += item->getGenres().at(i);
                if(i < item->getGenres().size() - 1) genres += ", ";
            }
            return genres;
        }

        default: return QString("DEFAULT");
        }
    } else if(role == 55) {
        if(dynamic_cast<Book *>(item)) return "Book";
        if(dynamic_cast<Cd *>(item)) return "Cd";
        if(dynamic_cast<Dvd *>(item)) return "Dvd";
        if(dynamic_cast<LibraryItemCollection *>(item)) return "LibraryItemCollection";
    }
    return QVariant();
}

void LibraryItemModel::addItem(LibraryItemComponent *item)
{
    beginInsertRows(QModelIndex(), items->size(), items->size());
    items->push_back(item);
    endInsertRows();
}

void LibraryItemModel::updateItems(QModelIndexList list)
{
    LibraryItemFactory factory;

    for(QModelIndex &item : list) {
        LibraryItemComponent *updatedItem = nullptr;

        if(dynamic_cast<Book *>(items->at(item.row()))) {
            updatedItem = factory.createItem(BookItem, items->at(item.row()));
        } else if(dynamic_cast<Cd *>(items->at(item.row()))) {
            updatedItem = factory.createItem(CdItem, items->at(item.row()));
        }  else if(dynamic_cast<Dvd *>(items->at(item.row()))) {
            updatedItem = factory.createItem(DvdItem, items->at(item.row()));
        }  else if(dynamic_cast<LibraryItemCollection *>(items->at(item.row()))) {
            updatedItem = factory.createItem(CollectionItem, items->at(item.row()));
        }

        if(updatedItem) {
            delete (*items)[item.row()];
            (*items)[item.row()] = updatedItem;
            emit dataChanged(item, item);
        }
    }
}

void LibraryItemModel::removeItems(QVector<int> &rows)
{
    beginRemoveRows(QModelIndex(), rows[0], rows[rows.size() - 1]);
    for(int i = rows.size() - 1; i >= 0; --i) {
        delete items->at(rows[i]);
        items->remove(rows[i]);
    }
    endRemoveRows();
}


