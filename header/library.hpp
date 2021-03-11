#ifndef LIBRARY_H
#define LIBRARY_H

#include <QMainWindow>
#include "libraryitemmodel.hpp"
#include "adminpage.hpp"
#include "libraryview.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Library; }
QT_END_NAMESPACE

class Library : public QMainWindow
{
    Q_OBJECT

public:
    Library(QWidget *parent = nullptr);
    ~Library();

private slots:
    void setPage(int pageNum = 1);

private:
    Ui::Library *ui;
    LibraryItemModel *model;
    LibraryView *libraryView;
    AdminPage *adminPage;
    QVector<LibraryItemComponent *> *items;

    void readItemsFromDatabase();
};
#endif // LIBRARY_H
