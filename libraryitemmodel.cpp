#include "libraryitemmodel.hpp"
#include "libraryitemfactory.hpp"
#include "book.hpp"

LibraryItemModel::LibraryItemModel(QVector<LibraryItemComponent *> *items, QObject *parent)
    : QAbstractTableModel(parent), items(items)
{
}

LibraryItemModel::~LibraryItemModel()
{
    for(int i = 0; i < items->size(); ++i) {
        delete items->at(i);
    }
    delete items;
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
        case 2 : return item->getCreatorStr();
        case 3 : return item->getYear();
        case 4 : return item->getLengthStr();
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
    } else if(role == 56) return item->getQuantity();
    else if(role == 57) return item->getId();
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
            if(dynamic_cast<LibraryItemCollection *>(updatedItem))
            {
                updateCollection(dynamic_cast<LibraryItemCollection *>(updatedItem));
            }

            else
            {
                updateItem(updatedItem);
            }
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
        //check whether item or collection
        if(dynamic_cast<LibraryItemCollection *>(items->at(rows[i])))
        {
            deleteCollection(items->at(rows[i])->getId());
        }

        else
        {
            deleteItem(items->at(rows[i])->getId());
        }
        delete items->at(rows[i]);
        items->remove(rows[i]);
    }
    endRemoveRows();
}

bool LibraryItemModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == 56) {
        items->at(index.row())->setQuantity(value.toInt());
    }
    emit dataChanged(index, index);
    return true;
}

//Heidi Changes
void LibraryItemModel::deleteItem(int id)
{
    //connect to item database
    if(connectToItemDB())
    {
        QSqlQuery query = QSqlQuery(db);
        query.prepare("DELETE FROM items WHERE id = ?");
        query.addBindValue(id);


        bool itemsSuccess = query.exec();
        qDebug() << "Item deletion: " << itemsSuccess;


        //close the database connection
        db.close();
        qDebug() << "Database has been closed";
    }

    else
    {
            qDebug() << "Could not add item to database";
    }
}

void LibraryItemModel::deleteCollection(int id)
{
    //connect to item database
    if(connectToItemDB())
    {
        QSqlQuery query = QSqlQuery(db);
        query.prepare("DELETE FROM collections WHERE id = ?");
        query.addBindValue(id);


        bool itemsSuccess = query.exec();
        qDebug() << "Collection deletion: " << itemsSuccess;


        //close the database connection
        db.close();
        qDebug() << "Database has been closed";
    }

    else
    {
            qDebug() << "Could not add item to database";
    }
}

bool LibraryItemModel::connectToItemDB()
{
    //connect to DB driver
    db = QSqlDatabase::addDatabase("QSQLITE");
    //database name
    QString dbName = "Items.db3";
    //try to connect to database
    db.setDatabaseName(dbName);
    db.open();
    //if we are able to connected into the database
    if(db.isOpen())
    {
        qDebug() << "Successfully connected to the database";
        //set a new query
        QSqlQuery query = QSqlQuery(db);
        //create account table if it does not exist
        query.exec( "CREATE TABLE IF NOT EXISTS items ( id INTEGER PRIMARY KEY AUTOINCREMENT, title TEXT, creator TEXT, year TEXT, length INTEGER, genres BLOB, quantity INTEGER, description TEXT, itemType TEXT )" );
        query.exec( "CREATE TABLE IF NOT EXISTS collections ( id INTEGER PRIMARY KEY AUTOINCREMENT, title TEXT, quantity INTEGER,  genres BLOB, year TEXT, description TEXT, children BLOB, creator TEXT )" );


        return true;

    }

    else
    {
        //account could not be added
        qDebug() << "Could not connect item to database";
        return false;
    }
}



QVector<LibraryItemComponent *> LibraryItemModel::parseItems(QByteArray byteArray)
{
    QVector<LibraryItemComponent *> collectionItems;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArray);
    QJsonArray jsonArray = jsonDoc.array();

    for(int i=0; i<jsonArray.count(); i++)
    {
        QJsonObject obj = jsonArray[i].toObject();
        int id = obj["id"].toInt();
        int quantity = obj["quantity"].toInt();
        QString title = obj["title"].toString();
        QString year = obj["year"].toString();
        //convert jsonArray to jsonDoc to qbytearray
        QJsonDocument genDoc(obj["genres"].toArray());
        QVector<QString> genres = parseGenres(genDoc.toJson(QJsonDocument::Compact));
        QString description = obj["description"].toString();
        QString creator = obj["creator"].toString();
        int length = obj["length"].toInt();
        int itemType = obj["itemType"].toInt();

        //check item type
        if(itemType == 0)
        {
            //Book
            collectionItems.push_back(new Book(title, quantity, genres, year, id, description, creator, length));
        }

        else if(itemType == 1)
        {
            //cd
            collectionItems.push_back(new Cd(title, quantity, genres, year, id, description, creator, length));
        }

        else if(itemType == 2)
        {
            //dvd
            collectionItems.push_back(new Dvd(title, quantity, genres, year, id, description, creator, length));
        }

    }

    return collectionItems;

}

QVector<QString> LibraryItemModel::parseGenres(QByteArray byteArray)
{
    QVector<QString> genres;

    QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArray);
    QJsonArray jsonArray = jsonDoc.array();
    for (int i=0; i<jsonArray.count(); i++)
    {
        QJsonObject obj = jsonArray[i].toObject();
        QString genre = obj["genre"].toString();
        genres.push_back(genre);
    }

    return genres;

}


void LibraryItemModel::updateItem(LibraryItemComponent *item)
{
    //connect to item database
    if(connectToItemDB())
    {
        //retrieve items from item
        QString title = item->getTitle();
        QString year = item->getYear();
        //QVector<QString> genres = item->getGenres();
        QString description = item->getDescription();
        int quantity = item->getQuantity();
        QString creator = item->getCreator();
        int length = item->getLength();
        QByteArray genres = convertGenreVectToArray(item->getGenres());

        int itemType = -1;

        if(dynamic_cast<Book *>(item))
        {
            itemType = 0;
        }

        else if(dynamic_cast<Cd *>(item))
        {
            itemType = 1;
        }

        else if(dynamic_cast<Dvd *>(item))
        {
            itemType = 2;
        }

        QSqlQuery query = QSqlQuery(db);
        query.prepare("UPDATE items SET title=(:t), creator=(:c), year=(:y), length=(:l), genres=(:g), quantity=(:q), description=(:d), itemType=(:iT) WHERE id=(:i)");
        query.bindValue(":t", title);
        query.bindValue(":c", creator);
        query.bindValue(":y", year);
        query.bindValue(":l", length);
        query.bindValue(":g", genres);
        query.bindValue(":q", quantity);
        query.bindValue(":d", description);
        query.bindValue(":iT", itemType);
        query.bindValue(":i", item->getId());

        bool itemsSuccess = query.exec();
        qDebug() << "Item Update: " << itemsSuccess;
        qDebug() << query.lastError();
        qDebug() << item->getId();
        //index of columns
        //id INTEGER PRIMARY KEY AUTOINCREMENT, title TEXT, creator TEXT, year TEXT, length INTEGER, genre BLOB, quantity INTEGER, description TEXT, itemType TEXT




        //close the database connection
        db.close();
        qDebug() << "Database has been closed";
    }

    else
    {
            qDebug() << "Could not add item to database";
    }
}

void LibraryItemModel::updateCollection(LibraryItemCollection *item)
{
        if(connectToItemDB())
        {

            //retrieve items from item
            QString title = item->getTitle();
            QString year = item->getYear();
            //QVector<QString> genres = item->getGenres();
            QString description = item->getDescription();
            int quantity = item->getQuantity();
            QString creator = item->getCreator();
            QByteArray genres = convertGenreVectToArray(item->getGenres());
            QByteArray children = convertItemVectToArray(item->getChildren());


            QSqlQuery query = QSqlQuery(db);
            query.prepare("INSERT INTO collections title=(:t), quantity=(:q), genres=(:g), year=(:y), description=(:d), children=(:ch), creator=(:c)) WHERE id =(:i)");
            query.bindValue(":t", title);
            query.bindValue(":q", quantity);
            query.bindValue(":g", genres);
            query.bindValue(":y", year);
            query.bindValue(":d", description);
            query.bindValue(":ch", children);
            query.bindValue(":c", creator);
            query.bindValue(":i", item->getId());

            bool itemsSuccess = query.exec();
            qDebug() << "Collection insert: " << itemsSuccess;
        //connect to collections database
        // id INTEGER PRIMARY KEY AUTOINCREMENT, title TEXT, quantity INTEGER,  genres BLOB, year TEXT, description TEXT, children BLOB, creator TEXT




        //close the database connection
        db.close();
        qDebug() << "Database has been closed";
        }

        else
        {
            qDebug() << "Could not add item to database";
        }
}

QByteArray LibraryItemModel::convertItemVectToArray(QVector<LibraryItemComponent *> itemVect)
{
    QJsonArray jsonArray;
    for (int i=0; i<itemVect.count(); i++)
    {
        QJsonObject obj;
        // check the type of object
        int itemType = -1;

        if(dynamic_cast<Book *>(itemVect[i]))
        {
            itemType = 0;
        }

        else if(dynamic_cast<Cd *>(itemVect[i]))
        {
            itemType = 1;
        }

        else if(dynamic_cast<Dvd *>(itemVect[i]))
        {
            itemType = 2;
        }
        obj.insert("title", QJsonValue::fromVariant(itemVect[i]->getTitle()));
        obj.insert("quantity", QJsonValue::fromVariant(itemVect[i]->getQuantity()));
        obj.insert("year", QJsonValue::fromVariant(itemVect[i]->getYear()));
        obj.insert("length", QJsonValue::fromVariant(itemVect[i]->getLength()));
        obj.insert("creator", QJsonValue::fromVariant(itemVect[i]->getCreator()));
        obj.insert("description", QJsonValue::fromVariant(itemVect[i]->getDescription()));
        obj.insert("genres", QJsonValue::fromVariant(itemVect[i]->getGenres()));
        obj.insert("id", QJsonValue::fromVariant(itemVect[i]->getId()));
        obj.insert("itemType", QJsonValue::fromVariant(itemType));
        jsonArray.push_back(obj);
    }

    QJsonDocument jsonDoc(jsonArray);
    QByteArray byteArray = jsonDoc.toJson(QJsonDocument::Compact);

    return byteArray;
}


QByteArray LibraryItemModel::convertGenreVectToArray(QVector<QString> genresVect)
{
    QJsonArray jsonArray;
    for (int i=0; i<genresVect.count(); i++)
    {
        QJsonObject obj;
        obj.insert("genre", QJsonValue::fromVariant(genresVect[i]));
        jsonArray.push_back(obj);
    }

    QJsonDocument jsonDoc(jsonArray);
    QByteArray byteArray = jsonDoc.toJson(QJsonDocument::Compact);

    return byteArray;
}
