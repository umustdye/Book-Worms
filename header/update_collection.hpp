#ifndef UPDATE_COLLECTION_HPP
#define UPDATE_COLLECTION_HPP


#include "update_strat.hpp"

class UpdateCollection : public UpdateStrat {
private:

public:
    UpdateCollection();
    ~UpdateCollection();
    virtual bool update(int id) override;
};


#endif
