#ifndef LIBRARYVIEW_HPP
#define LIBRARYVIEW_HPP

#include <QWidget>
#include "libraryitemmodel.hpp"
#include "libraryitemproxymodel.hpp"
#include "account.hpp"

namespace Ui {
class LibraryView;
}

class LibraryView : public QWidget
{
    Q_OBJECT

public:
    explicit LibraryView(LibraryItemModel *model, Account *user, QWidget *parent = nullptr);
    ~LibraryView();
    void resizeRow();

private slots:
    void on_bookCheckBox_toggled(bool checked);
    void on_cdCheckBox_toggled(bool checked);
    void on_dvdCheckBox_toggled(bool checked);
    void on_collectionCheckBox_toggled(bool checked);
    void on_searchBarLineEdit_textChanged(const QString &arg1);
    void on_homePushButton_clicked();
    void on_checkOutPushButton_clicked();

private:
    Ui::LibraryView *ui;
    LibraryItemProxyModel *proxy;
    Account *user;

signals:
    void changePage(int pageNum = 1);
};

#endif // LIBRARYVIEW_HPP
