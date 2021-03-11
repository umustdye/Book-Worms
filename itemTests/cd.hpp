#ifndef __CD_HPP__
#define __CD_HPP__

#include "item.hpp"
#include <QString>


class Cd : public LibraryItemComponent
{
private:
    QString artist;
    int tracks;

public:
    Cd(QString title="", int quantity=0, QVector<QString> genres = QVector<QString>(), QString year="", int id=-1, QString description="", QString artist="", int tracks=0);
    virtual ~Cd();
    void setArtist(QString artist);
    QString getArtist();
    void setTracks(int tracks);
    int getTracks();
    virtual QString stringifyItem() override;
};

#endif //__CD_HPP__
