#ifndef ADMINPAGE_HPP
#define ADMINPAGE_HPP

#include <QWidget>
#include <QVector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlIndex>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
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

    //Heidi helper functions
    QSqlDatabase db;
    bool connectToItemDB();
    void addItemToDB(LibraryItemComponent *item);
    void addCollectionToDB(LibraryItemCollection *item);
    QByteArray convertItemVectToArray(QVector<LibraryItemComponent *> itemVect);
    QByteArray convertGenreVectToArray(QVector<QString> genresVect);

signals:
    void changePage(int pageNum = 1);
};

#endif // ADMINPAGE_HPP
