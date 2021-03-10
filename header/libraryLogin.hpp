#ifndef LIBRARYLOGIN_H
#define LIBRARYLOGIN_H

#include <QWidget>
#include <QtSql>
#include <QDebug>
#include <QStackedWidget>

#include "header/account.hpp"
#include "header/user_items.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class LibraryLogin; }
QT_END_NAMESPACE

class LibraryLogin : public QWidget
{
    Q_OBJECT

public:
    LibraryLogin(QWidget *parent = nullptr);
    ~LibraryLogin();
    QString validLogin(QString userName, QString password);
    bool connectToAccountDB();
    void loadAccount(QString userName, QString password);
    QVector<userItems> parseObject(QByteArray byteArray);
    QSqlDatabase db;
    Account* account = new Account();
    //void setStackWidget();

private slots:
    void on_loginButton_clicked();

    void on_createAccountButton_clicked();

    void changeInputMessage(const QString &iconText);

private:
    Ui::LibraryLogin *ui;
};

#endif // LIBRARYLOGIN_H
