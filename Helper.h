#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "User.h"
#include <sstream>

using namespace std;

using namespace std;

void printChoices(){
    cout << "1. Exit the program." << endl;
    cout << "2. Create a new user." << endl;
    cout << "3. Make a bank account" << endl;
    cout << "4. Delete user" << endl;
    cout << "5. Delete bank account" << endl;
    cout << "6. Show users at bank" << endl;
    cout << "7. Show the acounts a user has" << endl;
    cout << "8. Deposit into an account" << endl;
    cout << "9. Withdraw from an account" << endl;

    // add other choices
}

User* createAccount(string nameInp, string lastNameInp,string emailInp,int phoneNumberInp,int ageInp,string usernameInp,string passwordInp) {
    //dynamically make new user
    User * userPtr; //user ptr
    userPtr = new User; //assign to user

    userPtr->setName(nameInp + " " + lastNameInp);
    userPtr->setEmail(emailInp);
    userPtr->setPhoneNum(phoneNumberInp);
    userPtr->setAge(ageInp);
    userPtr->setUserName(usernameInp);
    userPtr->setPassword(passwordInp); //remeber to hash later

    cout << "DEBUG:: Acount Created Succsessfully" << endl;

    return userPtr;
}

void askUserAcctQuestions(string &nameInp, string &lastNameInp,string &emailInp,int &phoneNumberInp,int &ageInp,string &usernameInp,string &passwordInp) {
    cout << "Please enter your name (first and last): " << endl;
    cin >> nameInp;
    cin >> lastNameInp;

    cout << "Please enter your email: " << endl;
    cin >> emailInp;

    cout << "Please enter your phone number: " << endl;
    cin >> phoneNumberInp;

    cout << "Please enter your age " << endl;
    cin >> ageInp;

    cout << "Please enter your user name: " << endl;
    cin >> usernameInp;

    cout << "Please enter your passwrod: " << endl;
    cin >> passwordInp;

    std::cout << "DEBUG::name: " << nameInp << " " << lastNameInp << ". email: " << emailInp << ". phone number: " << phoneNumberInp << ". age: " << " email: " << emailInp
    << ". username: " << usernameInp << ". password: " << passwordInp << std::endl;
}



void saveUsersToCSV(const unordered_map<int, User*>& users, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    // Write CSV header
    file << "UserID,Name,Email,Phone,Age,Username,Password\n";

    // Write each user’s data
    for (const auto& pair : users) {
        User* user = pair.second;
        file << user->getUserID() << "," << user->getName() << "," 
             << user->getEmail() << "," << user->getPhoneNum() << "," 
             << user->getAge() << "," << user->getUserName() << "," 
             << user->getPassword() << "\n";
    }

    file.close();
    cout << "Users saved to " << filename << " successfully!" << endl;
}


void loadUsersFromCSV(unordered_map<int, User*>& users, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    getline(file, line); // Skip header line

    while (getline(file, line)) {
        stringstream ss(line);
        string userID, name, email, phone, age, username, password;
        
        getline(ss, userID, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');
        getline(ss, age, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');

        // Convert necessary fields to integers
        int idVal = stoi(userID);
        int phoneNumVal = stoi(phone);
        int ageVal = stoi(age);

        // Create new User and store it
        User* user = new User(idVal, name, email, phoneNumVal, ageVal, username, password);
        users[idVal] = user;
    }

    file.close();
    cout << "Users loaded from " << filename << " successfully!" << endl;
}


void onProgramClose(){
    //save new users to csv file for data persistance
    
}
#endif