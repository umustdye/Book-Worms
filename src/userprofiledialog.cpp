#include "header/userprofiledialog.h"
#include "ui_userprofiledialog.h"
#include "header/libraryLogin.hpp"
#include "header/accountwidget.h"

UserProfileDialog::UserProfileDialog(QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::UserProfileDialog)
{
    ui->setupUi(this);

    AccountMainPage amp;                                        // !! change to libraryLogin class instead
    itemVector = amp.a->getItemVector();

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

    // delete ptr to account / libary objects

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

void UserProfileDialog::getIdsTitlesFromDB() {
    QSqlDatabase dbItem = QSqlDatabase::addDatabase("QSQLITE");
    dbItem.setDatabaseName("/home/chris/Documents/databases/items (copy).sqlite");
    bool ok = dbItem.open();

    if(ok) {
        qDebug() << "Successfully opened items database";

        QSqlQuery query;

        query.exec("SELECT id, title FROM items");

        while (query.next()) {
            itemIdTitle.push_back(qMakePair(query.value(0).toInt(), query.value(1).toString()));
            //qDebug() << query.value(0).toInt() << ", " << query.value(1).toString();
        }

        dbItem.close();
    }
    else {
        qDebug() << "Cannot open item database.";
    }
}

void UserProfileDialog::on_returnItemPushButton_clicked() {
    qDebug() << "Return Item Button Clicked";


}
