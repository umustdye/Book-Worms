#ifndef ADD_DVD_HPP
#define ADD_DVD_HPP


#inlcude "addstrat.hpp"

class AddDvd : public AddStrat {
private:

public:
    AddDvd();
    ~AddDvd();
    virtual bool add() override;
};


#endif
