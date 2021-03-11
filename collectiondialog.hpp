#ifndef COLLECTIONDIALOG_HPP
#define COLLECTIONDIALOG_HPP

#include <QDialog>
#include "collection.hpp"

namespace Ui {
class CollectionDialog;
}

class CollectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CollectionDialog(QWidget *parent = nullptr);
    ~CollectionDialog();
    LibraryItemCollection *create(LibraryItemCollection *item = nullptr);

private:
    Ui::CollectionDialog *ui;
    int id;
    LibraryItemCollection *collection;
    QVector<LibraryItemComponent *> subItems;

public slots:
    void accept() override;
    void reject() override;

private slots:
    void on_addBookPushButton_clicked();
    void on_addCdPushButton_clicked();
    void on_addDvdPushButton_clicked();
};

#endif // COLLECTIONDIALOG_HPP
