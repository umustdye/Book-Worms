#ifndef __DVD_HPP__
#define __DVD_HPP__

#include "item.hpp"

class Dvd : public LibraryItemComponent
{
private:
    QString director;
    int length;

public:
    Dvd(QString title="", int quantity=0, QVector<QString> genres = QVector<QString>(), QString year ="", int id=-1, QString description="", QString director="", int length=0);
    virtual ~Dvd();
    void setDirector(QString director);
    QString getDirector();
    void setLength(int length);
    int getLength();
};

#endif //__DVD_HPP__
