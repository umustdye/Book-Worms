#ifndef __COMMUNICATOR_HPP__
#define __COMMUNICATOR_HPP__

#include "../header/library.hpp"
#include <string>

class Communicator {
private:
    Library* library;
public:
    Communicator(Library* lib) : library(lib) {};
    virtual void change(std::string, int);
};

#endif //__COMMUNICATOR_HPP__
