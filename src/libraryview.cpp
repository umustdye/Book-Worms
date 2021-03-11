#include "libraryview.hpp"
#include "ui_libraryview.h"
#include "user_items.hpp"
#include <QDateTime>

LibraryView::LibraryView(LibraryItemModel *model, Account *user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LibraryView), proxy(nullptr), user(user)
{
    ui->setupUi(this);

    //Create proxy model to sort/filter passed in model
    proxy = new LibraryItemProxyModel(this);
    proxy->setDynamicSortFilter(true);
    proxy->setSourceModel(model);

    //Setup table view
    ui->tableView->setModel(proxy);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->horizontalHeader()->setSortIndicatorShown(true);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    //Resize
    resizeRow();
}

LibraryView::~LibraryView()
{
    delete ui;
    delete proxy;
}

void LibraryView::on_bookCheckBox_toggled(bool checked)
{
    Q_UNUSED(checked)
    proxy->toggleFilterBook();
}

void LibraryView::on_cdCheckBox_toggled(bool checked)
{
    Q_UNUSED(checked)
    proxy->toggleFilterCd();
}

void LibraryView::on_dvdCheckBox_toggled(bool checked)
{
    Q_UNUSED(checked)
    proxy->toggleFilterDvd();
}

void LibraryView::on_collectionCheckBox_toggled(bool checked)
{
    Q_UNUSED(checked)
    proxy->toggleFilterCollection();
}

void LibraryView::on_searchBarLineEdit_textChanged(const QString &arg1)
{
    proxy->setFilterRegularExpression(arg1);
}

void LibraryView::on_homePushButton_clicked()
{
    emit changePage(1);//To main page
}

void LibraryView::on_checkOutPushButton_clicked()
{
    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();

    for(QModelIndex ind : selected) {
        userItems item;
        item.id = proxy->sourceModel()->data(proxy->mapToSource(ind), 57).toInt();
        item.quantity = 1;
        item.dueDate = QDateTime::currentDateTime().addDays(14);
        if(ind.data(56).toInt() > 0) {
            user->addItem(item);
            proxy->sourceModel()->setData(proxy->mapToSource(ind), ind.data(56).toInt() - 1, 56);
            proxy->invalidate();
        }
        qDebug()<<"Item Id At Checkout: "<<item.id;
    }
}

void LibraryView::resizeRow()
{
    for(int i = 0; i < proxy->rowCount(); ++i) {
        ui->tableView->resizeRowToContents(i);
    }
}
