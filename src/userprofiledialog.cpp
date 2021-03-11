#include "userprofiledialog.h"
#include "ui_userprofiledialog.h"
#include "libraryLogin.hpp"
#include "accountwidget.h"

UserProfileDialog::UserProfileDialog(Account *user, QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::UserProfileDialog), user(user)
{
    ui->setupUi(this);

    createItemListView();
}


UserProfileDialog::~UserProfileDialog()
{
    delete ui;
}

void UserProfileDialog::createItemListView() {
    getIdsTitlesFromDB();

    QStandardItemModel *model = new QStandardItemModel(this);

    QList<QString> h, r;
    h.push_back("Item Name");
    h.push_back("Quantity");
    h.push_back("Due Date");
    model->setHorizontalHeaderLabels(h);

    for(int i = 0; i < user->getItemVector().size(); i++) {
        qDebug()<<"id: "<<user->getItemVector()[i].id;
        for(int j = 0; j < 3; j++) {

            if(j == 0) {
                QString str = "NULL";
                for(int k = 0; k < itemIdTitle.size(); k++) {
                    if(user->getItemVector()[i].id == itemIdTitle[k].first)
                        str = itemIdTitle[k].second;
                }
                model->setItem(i, j, new QStandardItem(QString("%0").arg(str)));
            }
            else if(j == 1) {
                ;
                model->setItem(i, j, new QStandardItem(QString("%0").arg(user->getItemVector()[i].quantity)));
            }
            else if(j == 2) {
                model->setItem(i, j, new QStandardItem(QString("%0").arg(user->getItemVector()[i].dueDate.toString())));
            }
            else {
                model->setItem(i, j, new QStandardItem(QString("%0").arg("NULL")));
            }
        }
    }

    //model->appendRow(user->getItemVector());

    ui->itemTableView->setModel(model);
    ui->itemTableView->resizeColumnsToContents();

    ui->itemTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->itemTableView->show();
}

void UserProfileDialog::updateDatabaseAfterReturn(int idNum, int qty) {

    if(connectToItemDB())
    {
        qDebug() << "Successfully updated items database";

        QSqlQuery query = QSqlQuery(db);

        query.exec("SELECT id, quantity FROM items");

        int newQty = 0;
        while (query.next()) {
            if(query.value(0) == idNum) {
                newQty = query.value(1).toInt();
            }
        }

        qty += newQty;

        query.prepare("UPDATE items SET quantity = :q WHERE id = :idNum");
        query.bindValue(":q", qty);
        query.bindValue(":idNum", idNum);
        query.exec();

        db.close();
    }
    else {
        qDebug() << "Cannot open item database for update";
    }
}

void UserProfileDialog::getIdsTitlesFromDB() {

    if(connectToItemDB()) {
        qDebug() << "Successfully opened items database";

        QSqlQuery query = QSqlQuery(db);

        query.exec("SELECT id, title FROM items");

        while (query.next()) {
            itemIdTitle.push_back(qMakePair(query.value(0).toInt(), query.value(1).toString()));
        }

        db.close();
    }
    else {
        qDebug() << "Cannot open item database";
    }
}

void UserProfileDialog::on_returnItemPushButton_clicked() {
    qDebug() << "Return Item Button Clicked";

    QItemSelectionModel *select = ui->itemTableView->selectionModel();

    QModelIndexList row = select->selectedRows();
    if(row.size() == 0) return;

    //
    QVector<QPair<int, int>> dbUpdateVector;

    for(int i = 0; i < row.size(); i++)
    {
        QModelIndex index = row.at(i);

        int id = 0;
        int qty = 0;
        for(int j = 0; j < itemIdTitle.size(); j++) {
            if(index.data().toString() == itemIdTitle[j].second) {
                id = itemIdTitle[j].first;
//                qDebug() << id;

                for(int k = 0; k < user->getItemVector().size(); k++) {
                    if(user->getItemVector()[k].id == id) {
                        qty = user->getItemVector()[k].quantity;
//                        qDebug() << qty;
                    }
                }

                user->setItemVector(user->delItem(user->getItemVector(), id));
                //update user database
                updateUserDB(user->getItemVector());

                dbUpdateVector.push_back(qMakePair(id, qty));
//                qDebug() << dbUpdateVector.front();
            }
        }
    }

    for(int i = 0; i < dbUpdateVector.size(); i++) {
        updateDatabaseAfterReturn(dbUpdateVector[i].first, dbUpdateVector[i].second);
    }

    createItemListView();
}

bool UserProfileDialog::connectToItemDB()
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


void UserProfileDialog::updateUserDB(QVector<userItems> items)
{
    //connect to account database
    if(connectToAccountDB())
    {
        //convert vect into qbytearray
        QByteArray itemsByte = convertVectToArray(items);
        QSqlQuery query = QSqlQuery(db);
        query.prepare("UPDATE items SET items = :item WHERE id = :idNum");
        query.bindValue(":item", itemsByte);
        query.bindValue(":idNum", user->getId());
        query.exec();

        //close item database
        db.close();
    }

    else
    {
        qDebug() << "Unable to update items in account database";
    }
}


bool UserProfileDialog::connectToAccountDB()
{
    //connect to DB driver
    db = QSqlDatabase::addDatabase("QSQLITE");
    //database name
    QString dbName = "Account.db3";
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
        query.exec( "CREATE TABLE IF NOT EXISTS account ( id INTEGER PRIMARY KEY AUTOINCREMENT, userName TEXT, password TEXT, firstName TEXT, lastName TEXT, accountType INTEGER )" );
        return true;

    }

    else
    {
        //account could not be added
        qDebug() << "Could not connect to database";
        return false;
    }

}


QByteArray UserProfileDialog::convertVectToArray(QVector<userItems> itemVect)
{
    QJsonArray jsonArray;
    for (int i=0; i<itemVect.count(); i++)
    {
        QJsonObject obj;
        obj.insert("id", QJsonValue::fromVariant(itemVect[i].id));
        obj.insert("quantity", QJsonValue::fromVariant(itemVect[i].quantity));
        obj.insert("dueDate", QJsonValue::fromVariant(itemVect[i].dueDate));
        jsonArray.push_back(obj);
    }

    QJsonDocument jsonDoc(jsonArray);
    QByteArray byteArray = jsonDoc.toJson(QJsonDocument::Compact);

    return byteArray;
}
