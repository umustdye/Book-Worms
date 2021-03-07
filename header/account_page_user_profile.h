#ifndef ACCOUNTPAGEUSERPROFILE_H
#define ACCOUNTPAGEUSERPROFILE_H

#include "accountwidget.h"
#include "userprofiledialog.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class AccountPageUserProfile; }
QT_END_NAMESPACE

class AccountPageUserProfile : public QWidget
{
    Q_OBJECT

public:
    AccountPageUserProfile(QWidget *parent = nullptr);
    ~AccountPageUserProfile();

private:
    Ui::AccountPageUserProfile *ui;
    Ui::AccountMainPage *ui1;
};
#endif // ACCOUNTPAGEUSERPROFILE_H
