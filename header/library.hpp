#ifndef LIBRARY_H
#define LIBRARY_H

#include <QMainWindow>
#include "libraryitemmodel.hpp"
#include "adminpage.hpp"
#include "libraryview.hpp"
#include "libraryLogin.hpp"
#include "account.hpp"
#include "accountwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Library; }
QT_END_NAMESPACE

class Library : public QMainWindow
{
    Q_OBJECT

public:
    Library(QWidget *parent = nullptr);
    ~Library();

private slots:
    void setPage(int pageNum = 1);

private:
    Ui::Library *ui;
    LibraryItemModel *model;
    LibraryView *catalogPage;
    AdminPage *adminPage;
    QVector<LibraryItemComponent *> *items;
    LibraryLogin *loginPage;
    Account *user;
    AccountMainPage *mainPage;

    void readItemsFromDatabase();
    void simulateAdmin();
};
#endif // LIBRARY_H
