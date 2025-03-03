#include "Account.h"

class Saving: public Account {
   
    private:
    virtual void setIntrestRate(double rate) {
        this->intrestRate = rate;
    }

    virtual double getIntrestRate() {
        return this->intrestRate;
    }

    virtual void deposit(double amount) {
        balence = (balence + amount);
        std::cout << amount << " deposited successfully into acount " << accountID << "!" << std::endl;
    }

    virtual bool withdraw(double amount) {
        //if account balence is less than 0
        if (balence > 0) {
            cout << "Balence is less than 0, you must have a postitive balence to withdraw money" << std::endl;
            return;
        }
        //if acct balence is more than 0
        if (balence >= 0) {
            if (amount > balence) {
                std::cout << "You cannot withdrawl more money than you have in your account, balence: " << balence << " " << "amount trying to withdraw: " << amount;
            }
            else {
                //withdraw
                balence = (balence - amount);
                std::cout << "Succsessfull withdrawl" << std::endl;
            }
        }
    }

    virtual void calculateIntrest() {
        double intrest;
        double originalBalence = balence;

        intrest = (balence * intrestRate);
        balence = intrest + balence;

        std::cout << "Original balence: " << originalBalence << ". Intrest generated: " << intrest << ". New balence: " << balence << endl;
    }

};