#include "../header/mock_library_item_component.hpp"
#include "../header/mock_user_account.hpp"
#include "../header/coordinator.hpp"

int main()
{
    Coordinator *coor = new Coordinator();

    MockLibraryItemComponent *item = new MockLibraryItemComponent(coor);
    MockUserAccount *user = new MockUserAccount(coor);

    coor->setItem(item);
    coor->setUser(user);

    item->giveItem();
    item->receiveItem();
    user->checkOutItem();
    user->returnItem();
    
    delete coor;
    delete item;
    delete user;

    return 0;
}
