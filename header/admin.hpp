#ifndef __ADMIN_HPP__
#define __ADMIN_HPP__

#include "user.hpp"
#include "add_strat.hpp"
#include "update_strat.hpp"
#include "remove_strat.hpp"

class Admin : public User {
private:
    AddStrat* add;
    UpdateStrat* update;
    RemoveStrat* remove;
    int itemType;
public:
    void addItem();
    void updateItem(int);
    void removeItem(int);
    void setItemType(int);
    int getItemType();
};

#endif //__ADMIN_HPP__
