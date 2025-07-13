#include "UserAccount.h"
#include <iostream>
#include <sstream>

UserAccount::UserAccount() : accountNumber(0), name(""), balance(0.0) {}

UserAccount::UserAccount(int accNum, const std::string& name, double balance)
    : accountNumber(accNum), name(name), balance(balance) {}

void UserAccount::deposit(double amount) {
    balance += amount;
}

bool UserAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

void UserAccount::display() const {
    std::cout << "Account #" << accountNumber << " - " << name << " - Balance: $" << balance << "\n";
}

int UserAccount::getAccountNumber() const {
    return accountNumber;
}

std::string UserAccount::getName() const {
    return name;
}

double UserAccount::getBalance() const {
    return balance;
}

std::string UserAccount::toFileString() const {
    std::ostringstream oss;
    oss << accountNumber << "," << name << "," << balance;
    return oss.str();
}

UserAccount UserAccount::fromFileString(const std::string& line) {
    std::istringstream iss(line);
    std::string token;
    int accNum;
    std::string name;
    double balance;

    std::getline(iss, token, ',');
    accNum = std::stoi(token);

    std::getline(iss, name, ',');

    std::getline(iss, token, ',');
    balance = std::stod(token);

    return UserAccount(accNum, name, balance);
}
