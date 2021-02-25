#ifndef REMOVE_CD_HPP
#define REMOVE_CD_HPP


#include "remove_strat.hpp"

class RemoveCd : public RemoveStrat {
private:

public:
    RemoveCd();
    ~RemoveCd();
    virtual bool remove(int id) override;
};



#endif
