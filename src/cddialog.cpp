#include "cddialog.hpp"
#include "ui_cddialog.h"

CdDialog::CdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CdDialog)
{
    ui->setupUi(this);
}

CdDialog::~CdDialog()
{
    delete ui;
}

Cd *CdDialog::create(int id)
{
    //Populate form if given id
    this->id = id;
    if(id >= 0) {
        //GET ITEM FROM LIBRARY LIST, LOAD VALUES
        ui->cdTitle->setText("Loaded Title");
        ui->cdArtist->setText("Loaded Artist");
        ui->cdDescriptionTextEdit->setText("Loaded Title");
        ui->cdYearSpinbox->setValue(1969);
        ui->cdQuantitySpinbox->setValue(69);
        ui->cdTracksSpinbox->setValue(69);
        ui->titleLabel->setText("Update Cd");
    }

    //Execute dialog
    this->exec();

    //Return created object
    return cd;
}

void CdDialog::accept()
{
    //Get values from form
    QString title = ui->cdTitle->text();
    QString artist = ui->cdArtist->text();
    QString description = ui->cdDescriptionTextEdit->toPlainText();
    int year = ui->cdYearSpinbox->value();
    int quantity = ui->cdQuantitySpinbox->value();
    int tracks = ui->cdTracksSpinbox->value();

    //Get all selected generes
    QVector<QString> genres;
    for(QListWidgetItem *item : ui->cdGenreList->selectedItems()) {
        genres.push_back(item->text());
    }

    //INSERT INTO DATABASE, GET NEW ID IF ADDING

    //Set library item data
    cd = new Cd(title, quantity, genres, QString::number(year), id, description, artist, tracks);

    //Accept dialog to close
    QDialog::accept();
}

void CdDialog::reject()
{
    cd = nullptr;
    QDialog::reject();
}
