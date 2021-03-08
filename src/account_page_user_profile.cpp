#include "account_page_user_profile.h"
#include "ui_account_page_user_profile.h"

AccountPageUserProfile::AccountPageUserProfile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AccountPageUserProfile)
{
    ui->setupUi(this);
}

AccountPageUserProfile::~AccountPageUserProfile()
{
    delete ui;
}
