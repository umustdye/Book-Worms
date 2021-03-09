#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include <QString>
#include <QVector>
class LibraryItemComponent
{
private:
    QString title;
    int quantity;
    QVector<QString> genres;
    QString year;
    int id;
    QString description;

public:
    LibraryItemComponent(QString title="", int quantity=0, QVector<QString> genres = QVector<QString>(), QString year="", int id=-1, QString description="");
    virtual ~LibraryItemComponent();
    void setTitle(QString title);
    QString getTitle();
    void setQuantity(int quantity);
    int getQuantity();
    void setGenres(QVector<QString> genres);
    void addGenre(QString genre);
    QVector<QString> getGenres();
    void setYear(QString year);
    QString getYear();
    void setId(int id);
    int getId();
    void setDescription(QString description);
    QString getDescription();
    virtual QString stringifyItem();
};

#endif //__ITEM_HPP__
