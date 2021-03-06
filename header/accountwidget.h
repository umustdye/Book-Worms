#ifndef ACCOUNTMAINPAGE_H
#define ACCOUNTMAINPAGE_H

#include "userprofiledialog.h"

#include "account.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class AccountMainPage; }
QT_END_NAMESPACE

class AccountMainPage : public QWidget
{
    Q_OBJECT

public:
    AccountMainPage(Account *user, QWidget *parent = nullptr);
    void checkAdminStatus();
    ~AccountMainPage();
    void checkAdminButtonEnable();

private slots:
    void on_logoutButton_clicked();
    void on_libraryButton_clicked();
    void on_profileButton_clicked();
    void on_adminButton_clicked();

signals:
    void changePage(int pageNum = 1);

private:
    Ui::AccountMainPage *ui;
    Account *user;
};

#endif // ACCOUNTMAINPAGE_

