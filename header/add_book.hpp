#ifndef ADDBOOK_HPP
#define ADDBOOK_HPP


#inlcude "addstrat.hpp"

class AddBook : public AddStrat {
private:

public:
    AddBook();
    ~AddBook();
    virtual bool add() override;
};


#endif
