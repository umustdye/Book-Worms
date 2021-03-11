#ifndef __COLLECTION_HPP__
#define __COLLECTION_HPP__

#include "item.hpp"
#include <QVector>
#include <QString>

class LibraryItemCollection : public LibraryItemComponent
{
private:
    QVector <LibraryItemComponent*> children;
    QString creator;

public:
    LibraryItemCollection(QString title="", int quantity=0, QVector<QString> genres = QVector<QString>(), QString year="", int id = -1, QString description="", QVector<LibraryItemComponent*> children = QVector<LibraryItemComponent*>(), QString creator = "");
    virtual ~LibraryItemCollection();
    void addChild(LibraryItemComponent* child);
    void removeChild(int index);
    LibraryItemComponent* getChild(int index);
    void setChildren(QVector<LibraryItemComponent*> children);
    QVector<LibraryItemComponent*> getChildren();
//    virtual QString stringifyItem() override;
    QString getCreator() const override;
    QString getLength() const override;
    QString getDescription() override;
};

#endif //__COLLECTION_HPP__

