#ifndef __BOOK_HPP__
#define __BOOK_HPP__

#include <string>

using std::string;

class Book
{
    private:
        std::string author;

    public:
        Book();
        Book(std::string author);
        void setAuthor(std::string author);
        std::string getAuthor();
};


#endif //__BOOK_HPP__
