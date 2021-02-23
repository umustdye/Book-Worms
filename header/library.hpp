#ifndef __LIBRARY_HPP__
#define __LIBRARY_HPP__

#include <string>

class Communicator;

class Library {
public:
    virtual void itemChange(Communicator*, std::string, int) = 0;
};

#endif //__LIBRARY_HPP__
