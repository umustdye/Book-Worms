#include "../header/mock_library_item_component.hpp"

void MockLibraryItemComponent::giveItem() {
    change();
}

void MockLibraryItemComponent::receiveItem() {
    change();
}
