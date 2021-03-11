#include "adminpage.hpp"
#include "ui_adminpage.h"
#include <algorithm>

AdminPage::AdminPage(LibraryItemModel *model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);

    this->model = model;
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);
    resize();
}

AdminPage::~AdminPage()
{
    delete ui;
}

void AdminPage::on_addItemPushButton_clicked()
{
    //Get type
    QString type = ui->selectItemComboBox->currentText();
    LibraryItemComponent *newItem = nullptr;

    //Create object with factory
    if(type == "Book") {
        newItem = fac.createItem(BookItem);
    } else if(type == "Cd") {
        newItem = fac.createItem(CdItem);
    } else if(type == "Dvd") {
        newItem = fac.createItem(DvdItem);
    } else if(type == "Collection") {
        newItem = fac.createItem(CollectionItem);
    }

    //Set to data and add to db
    if(newItem) {
        model->addItem(newItem);
        resize();
        if(dynamic_cast<LibraryItemCollection *>(newItem))
            addCollectionToDB(dynamic_cast<LibraryItemCollection *>(newItem));
        else
            addItemToDB(newItem);
    }
}

void AdminPage::on_deleteSelectedPushButton_clicked()
{

    QModelIndexList list = ui->tableView->selectionModel()->selectedRows();
    QVector<int> rows;

    for(QModelIndex &ind : list) {
        rows.push_back(ind.row());
    }
    std::sort(rows.begin(), rows.end());

    if(rows.size()) {
        model->removeItems(rows);
        resize();
    }
}

void AdminPage::on_updateSelectedPushButton_clicked()
{
    model->updateItems(ui->tableView->selectionModel()->selectedRows());
    resize();
}

void AdminPage::resize()
{
    for(int i = 0; i < model->rowCount(); ++i) {
        ui->tableView->resizeRowToContents(i);
    }
}

void AdminPage::on_pushButton_clicked()
{
    emit changePage(1);//To main page
}


//Heidi Helper Functions---------------------------------------------------------------------------------------------------
bool AdminPage::connectToItemDB()
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
        qDebug() << "Could not connect to database";
        return false;
    }
}

void AdminPage::addItemToDB(LibraryItemComponent *item)
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
        query.prepare("INSERT INTO items (title, creator, year, length, genres, quantity, description, itemType) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
        query.addBindValue(title);
        query.addBindValue(creator);
        query.addBindValue(year);
        query.addBindValue(length);
        query.addBindValue(genres);
        query.addBindValue(quantity);
        query.addBindValue(description);
        query.addBindValue(itemType);

        bool itemsSuccess = query.exec();
        qDebug() << "Item insert: " << itemsSuccess;
        //index of columns
        //id INTEGER PRIMARY KEY AUTOINCREMENT, title TEXT, creator TEXT, year TEXT, length INTEGER, genre BLOB, quantity INTEGER, description TEXT, itemType TEXT

        item->setId(query.lastInsertId().toInt());

        //close the database connection
        db.close();
        qDebug() << "Database has been closed";
    }

    else
    {
            qDebug() << "Could not add item to database";
    }
}
void AdminPage::addCollectionToDB(LibraryItemCollection *item)
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
            int length = item->getLength();
            QByteArray genres = convertGenreVectToArray(item->getGenres());
            QByteArray children = convertItemVectToArray(item->getChildren());


            QSqlQuery query = QSqlQuery(db);
            query.prepare("INSERT INTO collections (title, quantity, genres, year, description, children, creator) VALUES (?, ?, ?, ?, ?, ?, ?)");
            query.addBindValue(title);
            query.addBindValue(quantity);
            query.addBindValue(genres);
            query.addBindValue(year);
            query.addBindValue(description);
            query.addBindValue(children);
            query.addBindValue(creator);

            bool itemsSuccess = query.exec();
            qDebug() << "Collection insert: " << itemsSuccess;
        //connect to collections database
        // id INTEGER PRIMARY KEY AUTOINCREMENT, title TEXT, quantity INTEGER,  genres BLOB, year TEXT, description TEXT, children BLOB, creator TEXT

            item->setId(query.lastInsertId().toInt());


        //close the database connection
        db.close();
        qDebug() << "Database has been closed";
    }

    else
    {
            qDebug() << "Could not add item to database";
    }
}


QByteArray AdminPage::convertItemVectToArray(QVector<LibraryItemComponent *> itemVect)
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


QByteArray AdminPage::convertGenreVectToArray(QVector<QString> genresVect)
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
