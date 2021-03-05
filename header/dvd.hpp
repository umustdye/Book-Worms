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
        int length;
        
    public:
        Dvd(std::string title="", int quantity=0, std::vector<std::string> genres = std::vector<std::string>(), std::string year ="", int id=-1, std::string description="", std::string director="", int length=0);
        ~Dvd(){}
        void setDirector(std::string director);
        std::string getDirector();
        void setLength(int length);
        int getLength();
        virtual string stringifyItem() override;

};

#endif //__DVD_HPP__
