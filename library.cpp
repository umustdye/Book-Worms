#include "ui_library.h"
#include <QDebug>
#include "library.hpp"

Library::Library(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Library), model(nullptr),
      catalogPage(nullptr), adminPage(nullptr),
      items(new QVector<LibraryItemComponent*>()), loginPage(nullptr),
      user(nullptr), mainPage(nullptr)
{
    ui->setupUi(this);

    //Create user account
    user = new Account();

    //Create library items model
    readItemsFromDatabase();//Read items from database
    model = new LibraryItemModel(items, this);

    //Create widget pages
    catalogPage = new LibraryView(model, user, this);
    adminPage = new AdminPage(model, this);
    loginPage = new LibraryLogin(user, this);
    mainPage = new AccountMainPage(user, this);

    //Add to stacked widget
    ui->stackedWidget->addWidget(catalogPage);
    ui->stackedWidget->addWidget(adminPage);
    ui->stackedWidget->addWidget(loginPage);
    ui->stackedWidget->addWidget(mainPage);

    //Connect change page signals
    connect(catalogPage, &LibraryView::changePage, this, &Library::setPage);
    connect(adminPage, &AdminPage::changePage, this, &Library::setPage);
    connect(loginPage, &LibraryLogin::changePage, this, &Library::setPage);
    connect(mainPage, &AccountMainPage::changePage, this, &Library::setPage);

    //Set default widget
    ui->stackedWidget->setCurrentWidget(loginPage);
}

Library::~Library()
{
    delete ui;
    delete catalogPage;
    delete adminPage;
    delete model;
    delete loginPage;
    delete user;
    delete mainPage;
}

void Library::setPage(int pageNum)
{
    switch(pageNum) {
    case 0: {
        resetUser();
        ui->stackedWidget->setCurrentWidget(loginPage); break;
    }
    case 1: {
        this->user->setAccountType(static_cast<AccountType>(1));//SIMULATE ADMIN UNTIL CAN CHANGE IN DATABASE
        mainPage->checkAdminButtonEnable();
        ui->stackedWidget->setCurrentWidget(mainPage); break;
    }
    case 2: {
        catalogPage->resizeRow();
        ui->stackedWidget->setCurrentWidget(catalogPage); break;
    }
    case 3: ui->stackedWidget->setCurrentWidget(adminPage); break;
    }
}

//Heidi Changes
void Library::readItemsFromDatabase()
{
    //try to connect to DB
    if(connectToItemDB())
    {
        QSqlQuery query = QSqlQuery(db);
        query.prepare( "SELECT * FROM items" );
        query.exec();
        //index of columns
        //id INTEGER PRIMARY KEY AUTOINCREMENT, title TEXT, creator TEXT, year TEXT, length INTEGER, genre BLOB, quantity INTEGER, description TEXT, itemType TEXT
        int idNo = query.record().indexOf("id");
        int titleNo = query.record().indexOf("title");
        int creatorNo = query.record().indexOf("creator");
        int yearNo = query.record().indexOf("year");
        int lengthNo = query.record().indexOf("length");
        int genreNo = query.record().indexOf("genres");
        int quantityNo = query.record().indexOf("quantity");
        int descriptionNo = query.record().indexOf("description");
        int itemTypeNo = query.record().indexOf("itemType");


        while(query.next())
        {
            //get values from database
            int id = query.value(idNo).toInt();
            QString title = query.value(titleNo).toString();
            QString creator = query.value(creatorNo).toString();
            QString year = query.value(yearNo).toString();
            int length = query.value(lengthNo).toInt();
            QString description = query.value(descriptionNo).toString();
            int itemType = query.value(itemTypeNo).toInt();
            int quantity = query.value(quantityNo).toInt();
            QByteArray genreByte = query.value(genreNo).toByteArray();
            QVector<QString> genres = parseGenres(genreByte);
            //check item type
            if(itemType == 0)
            {
                //Book
                items->push_back(new Book(title, quantity, genres, year, id, description, creator, length));
            }

            else if(itemType == 1)
            {
                //cd
                items->push_back(new Cd(title, quantity, genres, year, id, description, creator, length));
            }

            else if(itemType == 2)
            {
                //dvd
                items->push_back(new Dvd(title, quantity, genres, year, id, description, creator, length));
            }

            qDebug() << "Item Title: " << title;
            qDebug() << "Item Description: " << description;
            qDebug() << "Id: " <<id;
            qDebug() << "Creator: "<<creator;

        }

        //-------------------------------------------------------------------

        //connect to collections database
        // id INTEGER PRIMARY KEY AUTOINCREMENT, title TEXT, quantity INTEGER,  genres BLOB, year TEXT, description TEXT, children BLOB, creator TEXT
        QSqlQuery query2 = QSqlQuery(db);
        query2.prepare("SELECT * FROM collections");
        query2.exec();
        //index of columns
        idNo = query2.record().indexOf("id");
        titleNo = query2.record().indexOf("title");
        creatorNo = query2.record().indexOf("creator");
        yearNo = query2.record().indexOf("year");
        genreNo = query2.record().indexOf("genres");
        quantityNo = query2.record().indexOf("quantity");
        descriptionNo = query2.record().indexOf("description");
        int childrenNo = query2.record().indexOf("children");


        while(query2.next())
        {
            //get values from database
            int id = query2.value(idNo).toInt();
            QString title = query2.value(titleNo).toString();
            QString creator = query2.value(creatorNo).toString();
            QString year = query2.value(yearNo).toString();
            QByteArray byteGenre = query2.value(genreNo).toByteArray();
            QString description = query2.value(descriptionNo).toString();
            QByteArray byteChildren = query2.value(childrenNo).toByteArray();
            QVector<QString> genres = parseGenres(byteGenre);
            int quantity = query2.value(quantityNo).toInt();
            QVector<LibraryItemComponent*> children = parseItems(byteChildren);
            items->push_back(new LibraryItemCollection(title, quantity, genres, year, id, description, children, creator));
        }

        //close the database connection
        db.close();
        qDebug() << "Database has been closed";
    }

    else
    {
            qDebug() << "Could not read items from database";
    }
}

bool Library::connectToItemDB()
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




QVector<LibraryItemComponent *> Library::parseItems(QByteArray byteArray)
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

QVector<QString> Library::parseGenres(QByteArray byteArray)
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

void Library::resetUser()
{
    user->setAccountType(static_cast<AccountType>(0));
    user->setFirstName("");
    user->setId(-1);
    user->setItemType(0);
    user->setLastName("");
    user->setPassword("");
    user->setUserName("");
    user->clearItemVector();
}
