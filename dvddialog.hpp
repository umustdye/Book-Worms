#ifndef DVDDIALOG_HPP
#define DVDDIALOG_HPP

#include <QDialog>
#include "dvd.hpp"

namespace Ui {
class DvdDialog;
}

class DvdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DvdDialog(QWidget *parent = nullptr);
    ~DvdDialog();
    Dvd* create(Dvd *item = nullptr);

private:
    Ui::DvdDialog *ui;
    Dvd *dvd;
    int id;

public slots:
    void accept() override;
    void reject() override;
};

#endif // DVDDIALOG_HPP
