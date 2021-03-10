#include "header/userprofiledialog.h"
#include "ui_userprofiledialog.h"
#include "header/libraryLogin.hpp"

UserProfileDialog::UserProfileDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserProfileDialog)
{
    ui->setupUi(this);
    createItemListView();
}

UserProfileDialog::~UserProfileDialog()
{
    delete ui;
}

void UserProfileDialog::createItemListView() {
    // TODO, delete these when integrated with library class part, still check connection to db though
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/chris/Documents/qt-to-push/ChristopherCE_qt-branch/databases/account.db3");


    bool ok = db.open();

    if(ok) {
        qDebug() << "Successfully opened account database";

        QSqlQuery query;

        query.exec( "CREATE TABLE IF NOT EXISTS account ( id INTEGER PRIMARY KEY AUTOINCREMENT, userName TEXT, password TEXT, firstName TEXT, lastName TEXT, accountType INTEGER, items BLOB )" );

    }
    else {
        qDebug() << "Cannot open account database.";
    }

    ////

    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery("SELECT items FROM account");
    model->setHeaderData(0, Qt::Horizontal, tr("Item Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Quantity"));
    model->setHeaderData(2, Qt::Horizontal, tr("Due Date"));

//    query.exec("SELECT items FROM account");


    ui->itemTableView->setModel(model);
    ui->itemTableView->show();

//    QTableView *itemTable = new QTableView;
//    itemTable->setModel(model);
//    itemTable->show();
}

void UserProfileDialog::on_returnItemPushButton_clicked() {
    qDebug() << "Return Item Button Clicked";
}
