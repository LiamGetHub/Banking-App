#ifndef BANK_H
#define BANK_h

#include <vector>
#include <iostream>
#include "User.H"
#include <unordered_map>

using namespace std;

class Bank {
    public:

    void addUser(User* newUser) {
        users[newUser->getUserID()] = newUser;
    }

    void deleteUser(int userID) {
        if (users.find(userID) != users.end()) {
            delete users[userID];  // Free memory
            users.erase(userID);    // Remove from map
            cout << "User deleted." << endl;
        } else {
            cout << "User not found." << endl;
        }
    }

    void printAllUsers() {
        if (users.empty()) {
            cout << "No users found in the bank." << endl;
            return;
        }
    
        cout << "List of all users in the bank:" << endl;
        for (const auto& pair : users) {  // Iterate over map
            User* user = pair.second;
            cout << "User ID: " << user->getUserID() << ", Name: " << user->getName() 
                 << ", Email: " << user->getEmail() << endl;
        }
    }
    

    void setBankName(string name) {
        this->bankName = name;
    }

    string getBankName() {
        return this->bankName;
    }

    private:
        string bankName;
        unordered_map<int, User*> users; // Key: userID, Value: User*
};



#endif