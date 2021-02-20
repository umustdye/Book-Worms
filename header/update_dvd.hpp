#ifndef UPDATE_DVD_HPP
#define UPDATE_DVD_HPP


#include "update_strat.hpp"

class UpdateDvd : public UpdateStrat {
private:

public:
    UpdateDvd();
    ~UpdateDvd();
    virtual bool update() override;
};


#endif
