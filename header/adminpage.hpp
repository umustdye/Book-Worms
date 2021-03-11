#ifndef ADMINPAGE_HPP
#define ADMINPAGE_HPP

#include <QWidget>
#include <QVector>
#include "libraryitemfactory.hpp"
#include "libraryitemmodel.hpp"

namespace Ui {
class AdminPage;
}

class AdminPage : public QWidget
{
    Q_OBJECT

public:
    explicit AdminPage(LibraryItemModel *model, QWidget *parent = nullptr);
    ~AdminPage();

private slots:
    void on_addItemPushButton_clicked();

    void on_deleteSelectedPushButton_clicked();

    void on_updateSelectedPushButton_clicked();

    void resize();

    void on_pushButton_clicked();

private:
    Ui::AdminPage *ui;
    LibraryItemModel *model;
    LibraryItemFactory fac;

signals:
    void changePage(int pageNum = 1);
};

#endif // ADMINPAGE_HPP
