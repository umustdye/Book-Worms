#ifndef LIBRARYLOGIN_H
#define LIBRARYLOGIN_H

#include <QWidget>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class LibraryLogin; }
QT_END_NAMESPACE

class LibraryLogin : public QWidget
{
    Q_OBJECT

public:
    LibraryLogin(QWidget *parent = nullptr);
    ~LibraryLogin();
    bool validLogin(QString userName, QString password);
    bool connectToAccountDB();
    void loadAccount(QString userName, QString password);
    QSqlDatabase db;

private slots:
    void on_loginButton_clicked();

    void on_createAccountButton_clicked();

    void changeInputMessage(const QString &iconText);

private:
    Ui::LibraryLogin *ui;

};
#endif // LIBRARYLOGIN_H
