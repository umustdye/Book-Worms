#include "../header/coordinator.hpp"

void Coordinator::setItem(MockLibraryItemComponent* i) {
    this->item = i;
}

void Coordinator::setUser(MockUserAccount *u) {
    this->userAcnt = u;
}

void Coordinator::itemChange(Communicator* comm, std::string str, int qty) {
    if(comm == item) {
        std::cout << "Item" << std::endl;
        std::cout << "Name: " << str << std::endl;
        std::cout << "Qty: " << qty << std::endl << std::endl;
    }
    else if(comm == userAcnt) {
        std::cout << "User Account" << std::endl;
        std::cout << "Name: " << str << std::endl;
        std::cout << "Qty: " << qty << std::endl << std::endl;
    }
}
