#ifndef UPDATE_STRAT_HPP
#define UPDATE_STRAT_HPP


class UpdateStrat {
private:

public:
    UpdateStrat();
    virtual bool update(int id) = 0;
};


#endif
