#ifndef REMOVE_DVD_HPP
#define REMOVE_DVD_HPP


#include "remove_strat.hpp"

class RemoveDvd : public RemoveStrat {
private:

public:
    RemoveDvd();
    ~RemoveDvd();
    virtual bool remove() override;
};



#endif
