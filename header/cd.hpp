#ifndef __CD_HPP__
#define __CD_HPP__

#include <string>
#include <vector>
#include "item.hpp"

using std::string;
using std::vector;

class Cd : public LibraryItemComponent
{
    private:
        std::string artist;
        int tracks;


    public:
        Cd(std::string title="", int quantity=0, std::vector<std::string> genres = std::vector<std::string>(), std::string year="", int id=-1, std::string description="", std::string artist="", int tracks=0);

        virtual ~Cd(){}
        void setArtist(std::string artist);

        std::string getArtist();

        void setTracks(int tracks);

        int getTracks();

        virtual string stringifyItem() override;
       

};

#endif //__CD_HPP__
