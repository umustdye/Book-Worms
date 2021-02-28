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

    public:
        Book(std::string author="", std::string title="", int quantity=0, std::vector<std::string> genres = std::vector<std::string>(), std::string year="", int id=0, std::string description="", int length=0);
        void setAuthor(std::string author);
        std::string getAuthor();
};


#endif //__BOOK_HPP__
