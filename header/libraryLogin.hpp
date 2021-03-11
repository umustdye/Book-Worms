#ifndef LIBRARYLOGIN_H
#define LIBRARYLOGIN_H

#include <QWidget>
#include <QtSql>
#include <QDebug>
#include <QStackedWidget>
#include <QDateTime>

#include "account.hpp"
#include "user_items.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class LibraryLogin; }
QT_END_NAMESPACE

class LibraryLogin : public QWidget
{
    Q_OBJECT

public:
    LibraryLogin(Account *user,QWidget *parent = nullptr);
    ~LibraryLogin();
    QString validLogin(QString userName, QString password);
    bool connectToAccountDB();
    void loadAccount(QString userName, QString password);
    QVector<userItems> parseObject(QByteArray byteArray);
    QSqlDatabase db;
    Account *account;

private slots:
    void on_loginButton_clicked();
    void on_createAccountButton_clicked();
    void changeInputMessage(const QString &iconText);

private:
    Ui::LibraryLogin *ui;

signals:
    void changePage(int pageNum = 1);
};

#endif // LIBRARYLOGIN_H
