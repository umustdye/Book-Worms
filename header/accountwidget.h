#ifndef ACCOUNTMAINPAGE_H
#define ACCOUNTMAINPAGE_H

#include "userprofiledialog.h"

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include <QDebug>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class AccountMainPage; }
QT_END_NAMESPACE

class AccountMainPage : public QWidget
{
    Q_OBJECT

public:
    AccountMainPage(QWidget *parent = nullptr);
    void createAccountClass();
    void checkAdminStatus();
    ~AccountMainPage();

private slots:
    void on_logoutButton_clicked();
    void on_libraryButton_clicked();
    void on_profileButton_clicked();
    void on_adminButton_clicked();

private:
    Ui::AccountMainPage *ui;
};

#endif // ACCOUNTMAINPAGE_H
