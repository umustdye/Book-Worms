#ifndef USERPROFILEDIALOG_H
#define USERPROFILEDIALOG_H

#include <QDialog>
#include <QTableView>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class UserProfileDialog; }
QT_END_NAMESPACE

class UserProfileDialog : public QDialog
{
    Q_OBJECT

public:
    UserProfileDialog(QWidget *parent = nullptr);
    ~UserProfileDialog();
    void createTableWidget();

private:
    Ui::UserProfileDialog *ui;
};
#endif // USERPROFILEDIALOG_H
