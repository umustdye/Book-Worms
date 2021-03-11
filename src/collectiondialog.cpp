#include "ui_collectiondialog.h"
#include "collectiondialog.hpp"
#include "bookdialog.hpp"
#include "cddialog.hpp"
#include "dvddialog.hpp"

CollectionDialog::CollectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CollectionDialog),
    collection(nullptr)
{
    ui->setupUi(this);
}

CollectionDialog::~CollectionDialog()
{
    delete ui;
}

LibraryItemCollection* CollectionDialog::create(LibraryItemCollection *item)
{
    //Populate form if given item
    if(item) {
        //GET ITEM FROM LIBRARY LIST, LOAD VALUES
        ui->collectionTitle->setText(item->getTitle());
        ui->collectionDescriptionTextEdit->setText(item->getDescription());
        ui->collectionYearSpinbox->setValue(item->getYear().toInt());
        ui->collectionQuantitySpinbox->setValue(item->getQuantity());
        ui->titleLabel->setText("Update Collection");
    }

    //Execute dialog
    this->exec();

    //Return created object
    return collection;
}

void CollectionDialog::accept()
{
    //Get values from form
    QString title = ui->collectionTitle->text();
    QString description = ui->collectionDescriptionTextEdit->toPlainText();
    int year = ui->collectionYearSpinbox->value();
    int quantity = ui->collectionQuantitySpinbox->value();

    //Get all selected generes
    QVector<QString> genres;
    for(QListWidgetItem *item : ui->collectionGenreList->selectedItems()) {
        genres.push_back(item->text());
    }

    //INSERT INTO DATABASE, GET NEW ID IF ADDING, ELSE USE OLD ID

    //Set library item data
    collection = new LibraryItemCollection(title, quantity, genres, QString::number(year), id, description, subItems);

    //Accept dialog to close
    QDialog::accept();
}

void CollectionDialog::reject()
{
    //Delete any objects created but not going into a collection
    for(LibraryItemComponent *subItem : subItems) {
        delete subItem;
    }
    collection = nullptr;
    QDialog::reject();
}

void CollectionDialog::on_addBookPushButton_clicked()
{
    BookDialog dialog;
    LibraryItemComponent *book = dialog.create();
    if(book) {
        subItems.push_back(book);
    }
}

void CollectionDialog::on_addCdPushButton_clicked()
{
    CdDialog dialog;
    LibraryItemComponent *cd = dialog.create();
    if(cd) {
        subItems.push_back(cd);
    }
}

void CollectionDialog::on_addDvdPushButton_clicked()
{
    DvdDialog dialog;
    LibraryItemComponent *dvd = dialog.create();
    if(dvd) {
        subItems.push_back(dvd);
    }
}
