#ifndef __COORDINATOR_HPP__
#define __COORDINATOR_HPP__

#include <iostream>

#include "../header/library.hpp"
#include "../header/mock_library_item_component.hpp"
#include "../header/mock_user_account.hpp"

class Coordinator : public Library {
private:
    MockLibraryItemComponent* item;
    MockUserAccount* userAcnt;
public:
    void setItem(MockLibraryItemComponent*);
    void setUser(MockUserAccount*);
    virtual void itemChange(Communicator*, std::string, int);
};

#endif //__COORDINATOR_HPP__
