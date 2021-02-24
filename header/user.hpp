#ifndef __USER_HPP__
#define __USER_HPP__

#include <string>
#include <vector>
#include <utility>

class User {
private:
    std::string userName;
    std::string password;
    std::string firstName;
    std::string lastName;
    std::vector<std::pair<int, int>> userItems;

public:
    void setUserName(std::string);
    void setPassword(std::string);
    void setFirstName(std::string);
    void setLastName(std::string);
    std::string getUserName();
    std::string getPassword();
    std::string getFirstName();
    std::string getLastName();
};

#endif //__USER_HPP__
