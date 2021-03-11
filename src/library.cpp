#include "ui_library.h"
#include <QDebug>
#include "library.hpp"

Library::Library(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Library), model(nullptr),
      catalogPage(nullptr), adminPage(nullptr),
      items(new QVector<LibraryItemComponent*>()), loginPage(nullptr),
      user(nullptr), mainPage(nullptr)
{
    ui->setupUi(this);

    //Create user account
    user = new Account();

    //Create library items model
    readItemsFromDatabase();//Read items from database
    model = new LibraryItemModel(items, this);

    //Simulate admin
    simulateAdmin();

    //Create widget pages
    catalogPage = new LibraryView(model, this);
    adminPage = new AdminPage(model, this);
    loginPage = new LibraryLogin(user, this);
    mainPage = new AccountMainPage(user, this);

    //Add to stacked widget
    ui->stackedWidget->addWidget(catalogPage);
    ui->stackedWidget->addWidget(adminPage);
    ui->stackedWidget->addWidget(loginPage);
    ui->stackedWidget->addWidget(mainPage);

    //Connect change page signals
    connect(catalogPage, &LibraryView::changePage, this, &Library::setPage);
    connect(adminPage, &AdminPage::changePage, this, &Library::setPage);
    connect(loginPage, &LibraryLogin::changePage, this, &Library::setPage);
    connect(mainPage, &AccountMainPage::changePage, this, &Library::setPage);

    //Set default widget
    ui->stackedWidget->setCurrentWidget(loginPage);
}

Library::~Library()
{
    delete ui;
    delete catalogPage;
    delete adminPage;
    delete model;
    qDeleteAll(*items);
    delete items;
    delete loginPage;
    delete user;
    delete mainPage;
}

void Library::setPage(int pageNum)
{
    qDebug()<<"account type: "<<user->getAccountType();
    //NEED TO CHECK IF ADMIN IN MAIN PAGE AFTER USER IS SET, NOT BEFORE

    switch(pageNum) {
    case 0: ui->stackedWidget->setCurrentWidget(loginPage); break;
    case 1: ui->stackedWidget->setCurrentWidget(mainPage); break;
    case 2: ui->stackedWidget->setCurrentWidget(catalogPage); break;
    case 3: ui->stackedWidget->setCurrentWidget(adminPage); break;
    }
}

void Library::readItemsFromDatabase()
{
    items->push_back(new Book("Title 1", 1, QVector<QString>(), "2001", 15));
    items->push_back(new Book("Title 2", 2, QVector<QString>(), "2002", 35));
    items->push_back(new Book("Title 3", 3, QVector<QString>(), "2003", 55));
}

void Library::simulateAdmin()
{
    user->setAccountType(admin);
}
