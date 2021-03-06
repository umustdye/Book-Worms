#ifndef USERPROFILEDIALOG_H
#define USERPROFILEDIALOG_H

#include <QDialog>
#include <QTableView>
#include <QtSql>
#include <QDebug>
#include <QPair>
#include <QStandardItemModel>
#include "account.hpp"
#include "libraryLogin.hpp"
#include "accountwidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class UserProfileDialog; }
QT_END_NAMESPACE

class UserProfileDialog : public QDialog
{
    Q_OBJECT

public:
    UserProfileDialog(Account *user, QDialog *parent = nullptr);                       // !! change to libraryLogin class
    ~UserProfileDialog();
    void createItemListView();
    void returnItem();
    void getIdsTitlesFromDB();
    QVector<QPair<int, QString>> itemIdTitle;
    void updateDatabaseAfterReturn(int, int);
    void updateUserDB(QVector<userItems> items);
    QByteArray convertVectToArray(QVector<userItems> itemVect);

private slots:
    void on_returnItemPushButton_clicked();

private:
    Ui::UserProfileDialog *ui;
    QSqlDatabase db;
    Account *user;

    bool connectToItemDB();
    bool connectToAccountDB();
};

#endif // USERPROFILEDIALOG_H
