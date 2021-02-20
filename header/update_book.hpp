#ifndef UPDATE_BOOK_HPP
#define UPDATE_BOOK_HPP


#include "update_strat.hpp"

class UpdateBook : public UpdateStrat {
private:

public:
    UpdateBook();
    ~UpdateBook();
    virtual bool update() override;
};


#endif
