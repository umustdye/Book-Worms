#ifndef __ADMIN_HPP__
#define __ADMIN_HPP__

#include "../header/user.hpp"
#include "../header/add_strat.hpp"
#include "../header/update_strat.hpp"
#include "../header/remove_strat.hpp"

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
