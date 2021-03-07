#ifndef CDDIALOG_HPP
#define CDDIALOG_HPP

#include <QDialog>
#include "cd.hpp"

namespace Ui {
class CdDialog;
}

class CdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CdDialog(QWidget *parent = nullptr);
    ~CdDialog();
    Cd *create(int id = -1);

private:
    Ui::CdDialog *ui;
    Cd *cd;
    int id;

public slots:
    void accept() override;
    void reject() override;
};

#endif // CDDIALOG_HPP
