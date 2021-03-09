#ifndef USERPROFILEDIALOG_H
#define USERPROFILEDIALOG_H

#include <QWidget>
#include <QDialog>

#include <QTableView>
#include <QSqlQueryModel>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class UserProfileDialog; }
QT_END_NAMESPACE

class UserProfileDialog : public QDialog
{
    Q_OBJECT

public:
    UserProfileDialog(QWidget *parent = nullptr);
    ~UserProfileDialog();
    void createItemListView();
    void returnItem();

private slots:
    void on_returnItemPushButton_clicked();

private:
    Ui::UserProfileDialog *ui;
};

#endif // USERPROFILEDIALOG_H
