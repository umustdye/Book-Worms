#include "header/userprofiledialog.h"
#include "ui_userprofiledialog.h"

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
    QTableView itemTableView;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/chris/Documents/qt-to-push/ChristopherCE_qt-branch/databases/account.sqlite");
    bool ok = db.open();

    if(ok) {
        qDebug() << "Successfully opened database";

        QSqlQuery query;

        query.exec( "CREATE TABLE IF NOT EXISTS account ( id INTEGER PRIMARY KEY AUTOINCREMENT, userName TEXT, password TEXT, firstName TEXT, lastName TEXT, accountType INTEGER )" );

    }
    else {
        qDebug() << "Cannot open database.";
    }
}
