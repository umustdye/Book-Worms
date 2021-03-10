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

Cd *CdDialog::create(Cd *item)
{
    //Populate form if given valid item
    if(item) {
        //GET ITEM FROM LIBRARY LIST, LOAD VALUES
        ui->cdTitle->setText(item->getTitle());
        ui->cdArtist->setText(item->getArtist());
        ui->cdDescriptionTextEdit->setText(item->getDescription());
        ui->cdYearSpinbox->setValue(item->getYear().toInt());
        ui->cdQuantitySpinbox->setValue(item->getQuantity());
        ui->cdTracksSpinbox->setValue(item->getTracks());
        ui->titleLabel->setText("Update cd");
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
