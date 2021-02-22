#ifndef __CD_HPP__
#define __CD_HPP__

#include <string>

using std::string;

class Cd 
{
    private:
        std::string artist;
        int tracks;


    public:
        Cd();

        Cd(std::string artist, int tracks);

        void setArtist(std::string artist);

        std::string getArtist();

        void setTracks(int tracks);

        int getTracks();

};

#endif //__CD_HPP__
