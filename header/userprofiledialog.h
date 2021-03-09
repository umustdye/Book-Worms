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

private:
    Ui::UserProfileDialog *ui;
};
#endif // USERPROFILEDIALOG_H
