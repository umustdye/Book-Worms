#include "../header/coordinator.hpp"

void Coordinator::setItem(MockLibraryItemComponent* i) {
    this->item = i;
}

void Coordinator::setUser(MockUserAccount *u) {
    this->userAcnt = u;
}

void Coordinator::itemChange(Communicator* comm) {
    if(comm == item) {
        std::cout << "Item" << std::endl;
    }
    else if(comm == userAcnt) {
        std::cout << "User Account" << std::endl;
    }
}