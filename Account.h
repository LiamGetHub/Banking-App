#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include "User.h"

using namespace std;

/*
* The idea of this class is to make it an unistantiable (abstract class) 
* boilerplate for future acounts such as checkings, savings, or investment.
* The child classes should overide 
*/
class Account {
    public:
        // Pure virtual function (forces derived classes to implement)
        virtual void deposit(double amount) = 0;
        virtual bool withdraw(double amount) = 0; // returns boolean value to indicate sucsess. Important to check for edge cases.
        virtual void calculateIntrest() = 0;
        virtual void setIntrestRate() = 0;
        virtual double getIntrestRate() = 0;

        double getBalence() {
            return this->balence;
        }

        Account(){
            accountID = -1;
            userPtr->setUserID(-1);
            acctName = "UKNOWN";
            double balence = 0;
        }

        virtual ~Account(){};

        
    protected:
        int accountID;
        User * userPtr;
        double intrestRate;
        string acctName;
        double balence;
};



#endif