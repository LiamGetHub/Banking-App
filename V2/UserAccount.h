#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <string>

class UserAccount {
private:
    int accountNumber;
    std::string name;
    double balance;

public:
    UserAccount();
    UserAccount(int accNum, const std::string& name, double balance);

    void deposit(double amount);
    bool withdraw(double amount);
    void display() const;

    int getAccountNumber() const;
    std::string getName() const;
    double getBalance() const;

    std::string toFileString() const;
    static UserAccount fromFileString(const std::string& line);
};

#endif
