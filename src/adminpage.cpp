#include "adminpage.hpp"
#include "ui_adminpage.h"
#include <algorithm>

AdminPage::AdminPage(LibraryItemModel *model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);

    this->model = model;
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);
    resize();
}

AdminPage::~AdminPage()
{
    delete ui;
}

void AdminPage::on_addItemPushButton_clicked()
{
    //Get type
    QString type = ui->selectItemComboBox->currentText();
    LibraryItemComponent *newItem = nullptr;

    //Create object with factory
    if(type == "Book") {
        newItem = fac.createItem(BookItem);
    } else if(type == "Cd") {
        newItem = fac.createItem(CdItem);
    } else if(type == "Dvd") {
        newItem = fac.createItem(DvdItem);
    } else if(type == "Collection") {
        newItem = fac.createItem(CollectionItem);
    }

    //Set to data
    if(newItem) {
        model->addItem(newItem);
        resize();
    }
}

void AdminPage::on_deleteSelectedPushButton_clicked()
{

    QModelIndexList list = ui->tableView->selectionModel()->selectedRows();
    QVector<int> rows;

    for(QModelIndex &ind : list) {
        rows.push_back(ind.row());
    }
    std::sort(rows.begin(), rows.end());

    if(rows.size()) {
        model->removeItems(rows);
        resize();
    }
}

void AdminPage::on_updateSelectedPushButton_clicked()
{
    model->updateItems(ui->tableView->selectionModel()->selectedRows());
    resize();
}

void AdminPage::resize()
{
    for(int i = 0; i < model->rowCount(); ++i) {
        ui->tableView->resizeRowToContents(i);
    }
}

void AdminPage::on_pushButton_clicked()
{
    emit changePage(1);//To main page
}
