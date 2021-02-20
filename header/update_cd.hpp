#ifndef UPDATE_CD_HPP
#define UPDATE_CD_HPP


#include "update_strat.hpp"

class UpdateCd : public UpdateStrat {
private:

public:
    UpdateCd();
    ~UpdateCd();
    virtual bool update() override;
};


#endif
