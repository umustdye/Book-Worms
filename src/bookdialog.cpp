#include "bookdialog.hpp"
#include "ui_bookdialog.h"

BookDialog::BookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookDialog),
    book(nullptr)
{
    ui->setupUi(this);
}

BookDialog::~BookDialog()
{
    delete ui;
}

Book* BookDialog::create(int id)
{
    //Populate form if given id
    this->id = id;
    if(id >= 0) {
        //GET ITEM FROM LIBRARY LIST, LOAD VALUES
        ui->bookTitle->setText("Loaded Title");
        ui->bookAuthor->setText("Loaded Author");
        ui->bookDescriptionTextEdit->setText("Loaded Description");
        ui->bookYearSpinbox->setValue(1969);
        ui->bookQuantitySpinbox->setValue(69);
        ui->bookPagesSpinbox->setValue(69);
        ui->titleLabel->setText("Update Book");
    }

    //Execute dialog
    this->exec();

    //Return created object
    return book;
}

void BookDialog::accept()
{
    //Get values from form
    QString title = ui->bookTitle->text();
    QString author = ui->bookAuthor->text();
    QString description = ui->bookDescriptionTextEdit->toPlainText();
    int year = ui->bookYearSpinbox->value();
    int quantity = ui->bookQuantitySpinbox->value();
    int pages = ui->bookPagesSpinbox->value();

    //Get all selected generes
    QVector<QString> genres;
    for(QListWidgetItem *item : ui->bookGenreList->selectedItems()) {
        genres.push_back(item->text());
    }

    //INSERT INTO DATABASE, GET NEW ID IF ADDING

    //Set library item data
    book = new Book(title, quantity, genres, QString::number(year), id, description, author, pages);

    //Accept dialog to close
    QDialog::accept();
}

void BookDialog::reject()
{
    book = nullptr;
    QDialog::reject();
}