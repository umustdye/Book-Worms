#include "../header/mock_user_account.hpp"

void MockUserAccount::checkOutItem() {
    change("checkOutItem", 3);
}

void MockUserAccount::returnItem() {
    change("returnItem", 4);
}
