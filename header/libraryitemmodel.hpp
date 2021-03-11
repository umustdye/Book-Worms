#ifndef LIBRARYITEMMODEL_H
#define LIBRARYITEMMODEL_H

#include <QAbstractTableModel>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include "item.hpp"
#include "collection.hpp"

class LibraryItemModel : public QAbstractTableModel
{
    Q_OBJECT

private:
    QVector<LibraryItemComponent *> *items;
    const int COLS = 7;
    QSqlDatabase db;

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
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    //
    //Heidi Changes
    void deleteItem(int id);
    void deleteCollection(int id);
    void updateItem(LibraryItemComponent *item);
    void updateCollection(LibraryItemCollection *item);
    bool connectToItemDB();
    QVector<LibraryItemComponent *> parseItems(QByteArray byteArray);
    QVector<QString> parseGenres(QByteArray byteArray);
    QByteArray convertGenreVectToArray(QVector<QString> genresVect);
    QByteArray convertItemVectToArray(QVector<LibraryItemComponent *> itemVect);
};

#endif // LIBRARYITEMMODEL_H
