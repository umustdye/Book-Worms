#ifndef __COMMUNICATOR_HPP__
#define __COMMUNICATOR_HPP__

#include "../header/library.hpp"

class Communicator {
private:
    Library* library;
public:
    Communicator(Library* lib) : library(lib) {};
    virtual void change();
};

#endif //__COMMUNICATOR_HPP__
