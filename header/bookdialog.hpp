#ifndef BOOKDIALOG_HPP
#define BOOKDIALOG_HPP

#include <QDialog>
#include "item.hpp"

namespace Ui {
class BookDialog;
}

class BookDialog : public QDialog
{
    Q_OBJECT
public:
    explicit BookDialog(QWidget *parent = nullptr);
    ~BookDialog();
    LibraryItemComponent *createItem(int id = -1);

private:
    Ui::BookDialog *ui;
    int id;

public slots:
    void accept() override;
    void reject() override;
};

#endif // BOOKDIALOG_HPP
