#ifndef USER_H
#define USER_H

#include <vector>
#include <string>

class User {
    public:

       // Constructor to initialize username and password
        User(const std::string& uname, const std::string& pwd) {
            userName = uname;  // Initialize 'username' with the provided value. Later can randomize
            password = pwd;    // Initialize 'password' with the provided value
        };
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