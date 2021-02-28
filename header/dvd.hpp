#ifndef __DVD_HPP__
#define __DVD_HPP__

#include <string>
#include <vector>
#include "item.hpp"

using std::string;
using std::vector;

class Dvd : public LibraryItemComponent
{
    private:
        std::string director;

    public:
        Dvd(std::string director= "", std::string title="", int quantity=0, std::vector<std::string> genres = std::vector<std::string>(), std::string year ="", int id=0, std::string description="", int length=0);
        void setDirector(std::string director);
        std::string getDirector();
};

#endif //__DVD_HPP__
