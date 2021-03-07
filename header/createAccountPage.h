#ifndef CREATEACCOUNTPAGE_H
#define CREATEACCOUNTPAGE_H

#include <QDialog>
#include <QtSql>
#include "account.h"


namespace Ui {
class CreateAccountPage;
}

class CreateAccountPage : public QDialog
{
    Q_OBJECT

public:
    explicit CreateAccountPage(QWidget *parent = nullptr);
    ~CreateAccountPage();
    bool connectToAccountDB();
    void addAccount(QString userName, QString password, QString firstName, QString lastName, AccountType accountType);
    bool validUserName(QString userName);
    bool validPassword(QString password);

private slots:
    void on_createButton_clicked();

private:
    Ui::CreateAccountPage *ui;
    QSqlDatabase db;
};

#endif // CREATEACCOUNTPAGE_H
