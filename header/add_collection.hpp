#ifndef ADD_COLLECTION_HPP
#define ADD_COLLECTION_HPP


#inlcude "addstrat.hpp"

class AddCollection : public AddStrat {
private:

public:
    AddCollection();
    ~AddCollection();
    virtual bool add() override;
};


#endif
