#ifndef ADD_CD_HPP
#define ADD_CD_HPP


#inlcude "addstrat.hpp"

class AddCd : public AddStrat {
private:

public:
    AddCd();
    ~AddCd();
    virtual bool add() override;
};


#endif
