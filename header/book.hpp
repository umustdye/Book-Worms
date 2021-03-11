#ifndef __BOOK_HPP__
#define __BOOK_HPP__
#include "item.hpp"

class Book : public LibraryItemComponent
{
private:
    QString author;
    int pages;

public:
    Book(QString title="", int quantity=0, QVector<QString> genres = QVector<QString>(), QString year="", int id=-1, QString description="", QString author = "", int pages=0);
    virtual ~Book();
    void setAuthor(QString author);
    QString getAuthor();
    void setPages(int pages);
    int getPages();
//    QString stringifyItem() override;
    QString getCreator() const override;
    void setCreator();
    QString getLength() const override;
};


#endif //__BOOK_HPP__
