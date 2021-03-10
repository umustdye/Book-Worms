#ifndef USERPROFILEDIALOG_H
#define USERPROFILEDIALOG_H

#include <QWidget>
#include <QDialog>

#include <QTableView>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include <QDebug>

#include <QPair>
#include <QStandardItemModel>

#include "header/account.hpp"
#include "header/libraryLogin.hpp"
#include "header/accountwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UserProfileDialog; }
QT_END_NAMESPACE

class UserProfileDialog : public QDialog
{
    Q_OBJECT

public:
    UserProfileDialog(QDialog *parent = nullptr);                       // !! change to libraryLogin class
    ~UserProfileDialog();
    void createItemListView();
    void returnItem();
    void getIdsTitlesFromDB();
    QVector<QPair<int, QString>> itemIdTitle;
    Account *acnt = new Account();
    QVector<userItems> itemVector;
    void updateDatabaseAfterReturn(int, int);

private slots:
    void on_returnItemPushButton_clicked();

private:
    Ui::UserProfileDialog *ui;
    QSqlDatabase dbItems = QSqlDatabase::addDatabase("QSQLITE");;
};

#endif // USERPROFILEDIALOG_H
