#ifndef __BOOK_HPP__
#define __BOOK_HPP__
#include "item.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;

class Book : public LibraryItemComponent
{
    private:
        std::string author;
        int pages;

    public:
        Book(std::string title="", int quantity=0, std::vector<std::string> genres = std::vector<std::string>(), std::string year="", int id=-1, std::string description="", std::string author = "", int pages=0);
        ~Book(){}
        void setAuthor(std::string author);
        std::string getAuthor();
        void setPages(int pages);
        int getPages();
        virtual string stringifyItem() override;

};


#endif //__BOOK_HPP__
