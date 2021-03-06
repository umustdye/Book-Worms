#include "bookdialog.hpp"
#include "ui_bookdialog.h"

BookDialog::BookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookDialog)
{
    ui->setupUi(this);
}

BookDialog::~BookDialog()
{
    delete ui;
}
