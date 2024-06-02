#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string userID;
    std::string password;

public:
    User(std::string uid = "", std::string pwd = "");
    virtual void displayMenu() const = 0;
};

#endif // USER_H
