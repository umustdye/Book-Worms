#include "../header/mock_user_account.hpp"

void MockUserAccount::checkOutItem() {
    change();
}

void MockUserAccount::returnItem() {
    change();
}
