#include "header/dvddialog.hpp"
#include "ui_dvddialog.h"

DvdDialog::DvdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DvdDialog)
{
    ui->setupUi(this);
}

DvdDialog::~DvdDialog()
{
    delete ui;
}

Dvd *DvdDialog::create(int id)
{
    //Populate form if given id
    this->id = id;
    if(id >= 0) {
        //GET ITEM FROM LIBRARY LIST, LOAD VALUES
        ui->dvdTitle->setText("Loaded Title");
        ui->dvdDirector->setText("Loaded Director");
        ui->dvdDescriptionTextEdit->setText("Loaded Title");
        ui->dvdYearSpinbox->setValue(1969);
        ui->dvdQuantitySpinbox->setValue(69);
        ui->dvdLengthSpinbox->setValue(69);
        ui->titleLabel->setText("Update Dvd");
    }

    //Execute dialog
    this->exec();

    //Return created object
    return dvd;
}

void DvdDialog::accept()
{
    //Get values from form
    QString title = ui->dvdTitle->text();
    QString director = ui->dvdDirector->text();
    QString description = ui->dvdDescriptionTextEdit->toPlainText();
    int year = ui->dvdYearSpinbox->value();
    int quantity = ui->dvdQuantitySpinbox->value();
    int length = ui->dvdLengthSpinbox->value();

    //Get all selected generes
    QVector<QString> genres;
    for(QListWidgetItem *item : ui->dvdGenreList->selectedItems()) {
        genres.push_back(item->text());
    }

    //INSERT INTO DATABASE, GET NEW ID IF ADDING

    //Set library item data
    dvd = new Dvd(title, quantity, genres, QString::number(year), id, description, director, length);

    //Accept dialog to close
    QDialog::accept();
}

void DvdDialog::reject()
{
    dvd = nullptr;
    QDialog::reject();
}
