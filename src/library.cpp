#include "library.hpp"
#include "ui_library.h"
#include <QDebug>

Library::Library(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Library), model(nullptr), libraryView(nullptr), adminPage(nullptr),  items(new QVector<LibraryItemComponent*>())
{
    ui->setupUi(this);

    //Create library items model
    readItemsFromDatabase();//Read items from database
    model = new LibraryItemModel(items, this);

    //Create widget pages
    libraryView = new LibraryView(model, this);
    adminPage = new AdminPage(model, this);

    //Add to stacked widget
    ui->stackedWidget->addWidget(libraryView);
    ui->stackedWidget->addWidget(adminPage);

    //Connect change page signals
    connect(libraryView, &LibraryView::changePage, this, &Library::setPage);
    connect(adminPage, &AdminPage::changePage, this, &Library::setPage);

    //Set default widget
    ui->stackedWidget->setCurrentWidget(adminPage);
}

Library::~Library()
{
    delete ui;
    delete libraryView;
    delete adminPage;
    delete model;
    qDeleteAll(*items);
    delete items;
}

void Library::setPage(int pageNum)
{
    switch(pageNum) {
//    case 0: ui->stackedWidget->setCurrentWidget(loginPage); break;
//    case 1: ui->stackedWidget->setCurrentWidget(mainPage); break;
    case 2: ui->stackedWidget->setCurrentWidget(libraryView); break;
    case 3: ui->stackedWidget->setCurrentWidget(adminPage); break;
    }
}

void Library::readItemsFromDatabase()
{
    items->push_back(new Book("Title 1", 1, QVector<QString>(), "2001", 15));
    items->push_back(new Book("Title 2", 2, QVector<QString>(), "2002", 35));
    items->push_back(new Book("Title 3", 3, QVector<QString>(), "2003", 55));
}
