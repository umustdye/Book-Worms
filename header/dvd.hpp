#ifndef __DVD_HPP__
#define __DVD_HPP__

#include <string>

using std::string;

class Dvd
{
    private:
        std::string director;

    public:
        Dvd();
        Dvd(std::string director);
        void setDirector(std::string director);
        std::string getDirector();
};

#endif //__DVD_HPP__
