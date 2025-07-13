#include "BankSystem.h"
#include <iostream>
#include <fstream>

BankSystem::BankSystem() : nextAccountNumber(1001) {
    loadAccounts();
}

void BankSystem::loadAccounts() {
    std::ifstream file("accounts.txt");
    std::string line;
    while (std::getline(file, line)) {
        UserAccount acc = UserAccount::fromFileString(line);
        accounts.push_back(acc);
        if (acc.getAccountNumber() >= nextAccountNumber) {
            nextAccountNumber = acc.getAccountNumber() + 1;
        }
    }
}

void BankSystem::saveAccounts() const {
    std::ofstream file("accounts.txt");
    for (const auto& acc : accounts) {
        file << acc.toFileString() << "\n";
    }
}

void BankSystem::createAccount() {
    std::string name;
    double initialDeposit;
    std::cout << "Enter name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter initial deposit: ";
    std::cin >> initialDeposit;

    UserAccount acc(nextAccountNumber++, name, initialDeposit);
    accounts.push_back(acc);
    saveAccounts();

    std::cout << "Account created.\n";
    acc.display();
}

UserAccount* BankSystem::findAccount(int accountNumber) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            return &acc;
        }
    }
    return nullptr;
}

void BankSystem::depositToAccount() {
    int accNum;
    double amount;
    std::cout << "Enter account number: ";
    std::cin >> accNum;

    UserAccount* acc = findAccount(accNum);
    if (acc) {
        std::cout << "Enter amount to deposit: ";
        std::cin >> amount;
        acc->deposit(amount);
        saveAccounts();
        std::cout << "Deposit successful.\n";
    } else {
        std::cout << "Account not found.\n";
    }
}

void BankSystem::withdrawFromAccount() {
    int accNum;
    double amount;
    std::cout << "Enter account number: ";
    std::cin >> accNum;

    UserAccount* acc = findAccount(accNum);
    if (acc) {
        std::cout << "Enter amount to withdraw: ";
        std::cin >> amount;
        if (acc->withdraw(amount)) {
            saveAccounts();
            std::cout << "Withdrawal successful.\n";
        } else {
            std::cout << "Insufficient funds.\n";
        }
    } else {
        std::cout << "Account not found.\n";
    }
}

void BankSystem::showAllAccounts() {
    for (const auto& acc : accounts) {
        acc.display();
    }
}

void BankSystem::run() {
    int choice;
    do {
        std::cout << "\n--- Banking Menu ---\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Show All Accounts\n";
        std::cout << "5. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositToAccount(); break;
            case 3: withdrawFromAccount(); break;
            case 4: showAllAccounts(); break;
            case 5: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}
