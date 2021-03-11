#include "libraryview.hpp"
#include "ui_libraryview.h"

LibraryView::LibraryView(LibraryItemModel *model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LibraryView), proxy(nullptr)
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

    //Resize to fit
    for(int i = 0; i < proxy->rowCount(); ++i) {
        ui->tableView->resizeRowToContents(i);
    }
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
