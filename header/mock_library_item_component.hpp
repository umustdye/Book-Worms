#ifndef __MOCK_LIBRARY_ITEM_COMPONENT_HPP__
#define __MOCK_LIBRARY_ITEM_COMPONENT_HPP__

#include "../header/communicator.hpp"

class MockLibraryItemComponent : public Communicator {
public:
    MockLibraryItemComponent(Library* lib) : Communicator(lib) {};
    void giveItem();
    void receiveItem();
};

#endif //__MOCK_LIBRARY_ITEM_COMPONENT_HPP__
