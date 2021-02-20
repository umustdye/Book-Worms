#ifndef REMOVE_BOOK_HPP
#define REMOVE_BOOK_HPP


#include "remove_strat.hpp"

class RemoveBook : public RemoveStrat {
private:

public:
    RemoveBook();
    ~RemoveBook();
    virtual bool remove() override;
};



#endif
