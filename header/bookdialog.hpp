#ifndef BOOKDIALOG_HPP
#define BOOKDIALOG_HPP

#include <QDialog>
#include "book.hpp"

namespace Ui {
class BookDialog;
}

class BookDialog : public QDialog
{
    Q_OBJECT
public:
    explicit BookDialog(QWidget *parent = nullptr);
    ~BookDialog();
    Book *create(Book *item = nullptr);

private:
    Ui::BookDialog *ui;
    int id;
    Book *book;

public slots:
    void accept() override;
    void reject() override;
};

#endif // BOOKDIALOG_HPP
