#include "UserAccount.h"
#include <iostream>
#include <sstream>
#include <functional> // for std::hash

UserAccount::UserAccount() : accountNumber(0), name(""), balance(0.0), passwordHash("") {}

UserAccount::UserAccount(int accNum, const std::string& name, const std::string& password, double balance)
    : accountNumber(accNum), name(name), balance(balance) {
    std::hash<std::string> hasher;
    passwordHash = std::to_string(hasher(password));
}

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
    oss << accountNumber << "," << name << "," << balance << "," << passwordHash;
    return oss.str();
}

UserAccount UserAccount::fromFileString(const std::string& line) {
    std::istringstream iss(line);
    std::string token, name, passwordHash;
    int accNum;
    double balance;

    std::getline(iss, token, ',');
    accNum = std::stoi(token);

    std::getline(iss, name, ',');

    std::getline(iss, token, ',');
    balance = std::stod(token);

    std::getline(iss, passwordHash, ',');

    UserAccount acc(accNum, name, "", balance);
    acc.passwordHash = passwordHash;

    return acc;
}

bool UserAccount::checkPassword(const std::string& password) const {
    std::hash<std::string> hasher;
    return passwordHash == std::to_string(hasher(password));
}
