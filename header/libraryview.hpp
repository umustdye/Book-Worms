#ifndef LIBRARYVIEW_HPP
#define LIBRARYVIEW_HPP

#include <QWidget>
#include "libraryitemmodel.hpp"
#include "libraryitemproxymodel.hpp"

namespace Ui {
class LibraryView;
}

class LibraryView : public QWidget
{
    Q_OBJECT

public:
    explicit LibraryView(LibraryItemModel *model, QWidget *parent = nullptr);
    ~LibraryView();

private slots:
    void on_bookCheckBox_toggled(bool checked);
    void on_cdCheckBox_toggled(bool checked);
    void on_dvdCheckBox_toggled(bool checked);
    void on_collectionCheckBox_toggled(bool checked);
    void on_searchBarLineEdit_textChanged(const QString &arg1);
    void on_homePushButton_clicked();

private:
    Ui::LibraryView *ui;
    LibraryItemProxyModel *proxy;

signals:
    void changePage(int pageNum = 1);

};

#endif // LIBRARYVIEW_HPP
