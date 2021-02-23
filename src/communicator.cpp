#include "../header/communicator.hpp"

void Communicator::change(std::string item, int qty) {
    library->itemChange(this, item, qty);
}
