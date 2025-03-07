#ifndef USER_H
#define USER_H

#include <vector>
#include <string>

using namespace std;

class User {
    public:

       // Constructor to initialize username and password User* user = new User(userID, name, email, phoneNum, ageVal, username, password);
        // User(int userId, string name, string email, int phoneNum, int ageVal,string username, int password) {
        //     userID = userId;
        //     name = name;
        //     email = email;
        //     phoneNum = phoneNum;
        //     age = ageVal;
        //     userName = username;  // Initialize 'username' with the provided value. Later can randomize
        //     password = password;    // Initialize 'password' with the provided value
        // };

        // Constructor that accepts all member variables
        User(int id, const std::string& name, const std::string& email, 
        int phoneNum, int age, const std::string& username, const std::string& password) 
       : userID(id), name(name), email(email), phoneNum(phoneNum), 
         age(age), userName(username), password(password) {}

        User() {
            userName = "uname";  // Initialize 'username' with the provided value. Later can randomize
            password = "pwd";    // Initialize 'password' with the provided value
        };

        std::string getName() {
            return name;
        };

        void setName(std::string name) {
            this->name = name;
        };


        std::string getEmail(){
            return email;
        }
        void setEmail(std::string email) {
            this->email = email;
        }


        int getPhoneNum() {
            return phoneNum;
        }
        void setPhoneNum(int phoneNum) {
            this->phoneNum = phoneNum;
        }

        int getAge() {
            return age;
        }
        void setAge(int age) {
            this->age = age;
        }

        std::string getUserName() {
            return userName;
        }
        void setUserName(std::string userName) {
            this->userName = userName;
        }

        std::string getPassword() {
            return password;
        }
        void setPassword(std::string password) {
            this->password = password;
        }

        int getUserID() {
            return this->userID;
        }
        void setUserID(int id){
            this->userID = id;
        }

        

    private:
        std::string name;
        std::string email;
        int phoneNum;
        int age;
        std::string userName;
        std::string password;
        std::string adress; // no getter or setter for this. make a struct or class for this later depending.
        int userID;
};



#endif 