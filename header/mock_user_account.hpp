#ifndef __MOCK_USER_ACCOUNT_HPP__
#define __MOCK_USER_ACCOUNT_HPP__

#include "../header/communicator.hpp"

class MockUserAccount : public Communicator{
public:
    MockUserAccount(Library* lib) : Communicator(lib) {};
    void checkOutItem();
    void returnItem();
};

#endif //__MOCK_USER_ACCOUNT_HPP__
