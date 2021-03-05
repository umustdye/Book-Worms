#ifndef REMOVE_COLLECTION_HPP
#define REMOVE_COLLECTION_HPP


#include "remove_strat.hpp"

class RemoveCollection : public RemoveStrat {
private:

public:
    RemoveCollection();
    ~RemoveCollection();
    virtual bool remove(int id) override;
};



#endif
