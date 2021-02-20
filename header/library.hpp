#ifndef __LIBRARY_HPP__
#define __LIBRARY_HPP__

class Communicator;

class Library {
public:
    virtual void itemChange(Communicator*) = 0;
};

#endif //__LIBRARY_HPP__
