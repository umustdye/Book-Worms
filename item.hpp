#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include <QString>
#include <QVector>
class LibraryItemComponent
{
private:
    QString title;
    QString year;
    QString description;
    int quantity;
    int id;
    QVector<QString> genres;


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
    virtual QString getDescription();
    virtual QString getCreator() = 0;
    virtual int getLength() = 0;
    virtual QString getCreatorStr() const = 0;
    virtual QString getLengthStr() const = 0;
//    virtual QString stringifyItem();
};

#endif //__ITEM_HPP__
