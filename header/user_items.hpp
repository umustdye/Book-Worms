#ifndef __USER_ITEMS_HPP__
#define __USER_ITEMS_HPP__

#include <QDateTime>

struct userItems {
    int id;
    int quantity;
    QDateTime dueDate;
};

#endif //__USER_ITEMS_HPP__
