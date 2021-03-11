#include "userprofiledialog.h"
#include "ui_userprofiledialog.h"
#include "libraryLogin.hpp"
#include "accountwidget.h"

UserProfileDialog::UserProfileDialog(Account *user, QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::UserProfileDialog), user(user)
{
    ui->setupUi(this);

    itemVector = user->getItemVector();

    // delete this
//    qDebug() << "FROM OTHER CLASS(Constructor): ";
//    for(int i = 0; i < itemVector.count(); i++) {
//        qDebug() << itemVector[i].id;
//        qDebug() << itemVector[i].quantity;
//        qDebug() << itemVector[i].dueDate;
//    }

    createItemListView();
}


UserProfileDialog::~UserProfileDialog()
{
    delete ui;
}

void UserProfileDialog::createItemListView() {

    ////

    // get the pair of ids and titles from items database
    getIdsTitlesFromDB();

    QStandardItemModel *model = new QStandardItemModel();

    QList<QString> h, r;
    h.push_back("Item Name");
    h.push_back("Quantity");
    h.push_back("Due Date");
    model->setHorizontalHeaderLabels(h);

    for(int i = 0; i < itemVector.size(); i++) {

        for(int j = 0; j < 3; j++) {

            QStandardItem *item;
            if(j == 0) {
                QString str = "NULL";
                for(int k = 0; k < itemIdTitle.size(); k++) {
                    if(itemVector[i].id == itemIdTitle[k].first)
                        str = itemIdTitle[k].second;
                }
                item = new QStandardItem(QString("%0").arg(str));
            }
            else if(j == 1) {
                item = new QStandardItem(QString("%0").arg(itemVector[i].quantity));
            }
            else if(j == 2) {
                item = new QStandardItem(QString("%0").arg(itemVector[i].dueDate.toString()));
            }
            else {
                item = new QStandardItem(QString("%0").arg("NULL"));
            }

            model->setItem(i, j, item);
            //delete item;
        }
    }

    //model->appendRow(itemVector);

    ui->itemTableView->setModel(model);
    ui->itemTableView->resizeColumnsToContents();

    ui->itemTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->itemTableView->show();


    // delete this
//    qDebug() << "END OF FUNCTION TEST: ";
//    for(int i = 0; i < itemVector.count(); i++) {
//        qDebug() << itemVector[i].id;
//        qDebug() << itemVector[i].quantity;
//        qDebug() << itemVector[i].dueDate;
//    }
}

void UserProfileDialog::updateDatabaseAfterReturn(int idNum, int qty) {
    dbItems.setDatabaseName("/home/chris/Documents/databases/items (copy).sqlite");
    bool ok = dbItems.open();

    if(ok) {
        qDebug() << "Successfully updated items database";

        QSqlQuery query;

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

        dbItems.close();
    }
    else {
        qDebug() << "Cannot open item database for update";
    }
}

void UserProfileDialog::getIdsTitlesFromDB() {
    dbItems.setDatabaseName("/home/chris/Documents/databases/items (copy).sqlite");
    bool ok = dbItems.open();

    if(ok) {
        qDebug() << "Successfully opened items database";

        QSqlQuery query;

        query.exec("SELECT id, title FROM items");

        while (query.next()) {
            itemIdTitle.push_back(qMakePair(query.value(0).toInt(), query.value(1).toString()));
            //qDebug() << query.value(0).toInt() << ", " << query.value(1).toString();
        }

        dbItems.close();
    }
    else {
        qDebug() << "Cannot open item database";
    }
}

void UserProfileDialog::on_returnItemPushButton_clicked() {
    qDebug() << "Return Item Button Clicked";

    QItemSelectionModel *select = ui->itemTableView->selectionModel();

    QModelIndexList row = select->selectedRows();

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

                for(int k = 0; k < itemVector.size(); k++) {
                    if(itemVector[k].id == id) {
                        qty = itemVector[k].quantity;
//                        qDebug() << qty;
                    }
                }

                itemVector = user->delItem(itemVector, id);

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
