#include "header/userprofiledialog.h"
#include "ui_userprofiledialog.h"

UserProfileDialog::UserProfileDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserProfileDialog)
{
    ui->setupUi(this);
    createTableWidget();
}

UserProfileDialog::~UserProfileDialog()
{
    delete ui;
}

void UserProfileDialog::createTableWidget() {
    QTableView itemTableView;

}
