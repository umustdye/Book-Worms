#ifndef __CD_HPP__
#define __CD_HPP__

#include <string>

using std::string;

class Cd 
{
    private:
        std::string artist;
        int tracks;
        //std::string* songs;


    public:
        Cd();

        //Cd(std::string artist, tracks, std::string* songs);
        Cd(std::string artist, int tracks);

        void setArtist(std::string artist);

        std::string getArtist();

        void setTracks(int tracks);

        int getTracks();

/*
        void setSongs(std::string* songs);

        void addSongs(std::string song);

        std::string* getSongs();
        
        std::string getSong(int trackNum);

*/
};

#endif //__CD_HPP__
