#ifndef __LIBRARY_HPP__
#define __LIBRARY_HPP__

#include "account.hpp"
#include "item.hpp"

class Library {
private:
    Account* acnt;
    LibraryItemComponent* item;

public:
    Library(Account* a, LibraryItemComponent* i);
    ~Library();
    void checkOutItem();
    void returnItem();
};

#endif //__LIBRARY_HPP__
