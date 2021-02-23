#include "../header/mock_library_item_component.hpp"

void MockLibraryItemComponent::giveItem() {
    change("giveItem", 1);
}

void MockLibraryItemComponent::receiveItem() {
    change("receiveItem", 2);
}
