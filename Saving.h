#ifndef SAVING_H
#define SAVING_H

#include "Account.h"

class Saving : public Account {
public:
    // Constructor
    Saving() {
        intrestRate = 0.01;
        balence = 0;
    }

    // Implement all pure virtual methods

    void deposit(double amount) override {
        balence += amount;
        std::cout << amount << " deposited successfully into account " << accountID << "!" << std::endl;
    }

    bool withdraw(double amount) override {
        if (balence <= 0) {
            std::cout << "Balance is less than or equal to 0. You must have a positive balance to withdraw money." << std::endl;
            return false;
        }
        if (amount > balence) {
            std::cout << "You cannot withdraw more money than you have. Balance: " << balence
                      << ", Requested: " << amount << std::endl;
            return false;
        }
        balence -= amount;
        std::cout << "Successful withdrawal." << std::endl;
        return true;
    }

    void calculateIntrest() override {
        double interest = balence * intrestRate;
        balence += interest;
        std::cout << "Interest added: " << interest << ". New balance: " << balence << std::endl;
    }

    void setIntrestRate(double rate) override {
        intrestRate = rate;
    }

    double getIntrestRate() override {
        return intrestRate;
    }
};



#endif