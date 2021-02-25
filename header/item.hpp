#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include <string>
#include <vector>

using std::string;
using std::vector;

class LibraryItemComponent
{
    private:
        std::string title;
        int quantity;
        std::vector<std::string> genres;
        std::string year;
        int id;

    public:
        LibraryItemComponent(std::string title="", int quantity=0, std::vector<std::string> genres = std::vector<std::string>(), std::string year="", int id=0);

        virtual void setTitle(std::string title);
        virtual std::string getTitle();
        virtual void setQuantity(int quantity);
        virtual int getQuantity();
        virtual void setGenres(std::vector<std::string> genres);
        virtual void addGenre(std::string genre);
        virtual std::vector<std::string> getGenres();
        virtual void setYear(std::string year);
        virtual std::string getYear();
        virtual void setId(int id);
        virtual int getId();
        virtual std::string stringifyItem();

};

#endif //__ITEM_HPP__
