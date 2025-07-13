#include "BankSystem.h"
#include <iostream>
#include <fstream>
#include <limits>

BankSystem::BankSystem() : nextAccountNumber(1001), currentUser(nullptr) {
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

UserAccount* BankSystem::findAccount(int accountNumber) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            return &acc;
        }
    }
    return nullptr;
}

void BankSystem::createAccount() {
    std::string name;
    double initialDeposit;
    std::string password;

    std::cout << "Enter name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter initial deposit: ";
    std::cin >> initialDeposit;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Create password: ";
    std::getline(std::cin, password);

    UserAccount acc(nextAccountNumber++, name, password, initialDeposit);
    accounts.push_back(acc);
    saveAccounts();

    std::cout << "Account created.\n";
    acc.display();
}

void BankSystem::login() {
    int accNum;
    std::string password;

    std::cout << "Enter account number: ";
    std::cin >> accNum;

    std::cin.ignore();
    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    UserAccount* acc = findAccount(accNum);
    if (acc && acc->checkPassword(password)) {
        currentUser = acc;
        std::cout << "Login successful. Welcome, " << currentUser->getName() << "!\n";
    } else {
        std::cout << "Invalid credentials.\n";
    }
}

void BankSystem::logout() {
    if (currentUser) {
        std::cout << "User " << currentUser->getName() << " logged out.\n";
        currentUser = nullptr;
    } else {
        std::cout << "No user is currently logged in.\n";
    }
}

void BankSystem::depositToAccount() {
    if (!currentUser) {
        std::cout << "Please login first.\n";
        return;
    }
    double amount;
    std::cout << "Enter amount to deposit: ";
    std::cin >> amount;
    currentUser->deposit(amount);
    saveAccounts();
    std::cout << "Deposit successful.\n";
}

void BankSystem::withdrawFromAccount() {
    if (!currentUser) {
        std::cout << "Please login first.\n";
        return;
    }
    double amount;
    std::cout << "Enter amount to withdraw: ";
    std::cin >> amount;
    if (currentUser->withdraw(amount)) {
        saveAccounts();
        std::cout << "Withdrawal successful.\n";
    } else {
        std::cout << "Insufficient funds.\n";
    }
}


void BankSystem::transferToAnotherAccount() {
    if (!currentUser) {
        std::cout << "Please login first.\n";
        return;
    }

    int targetAccNum;
    double amount;

    std::cout << "Enter target account number: ";
    std::cin >> targetAccNum;

    if (targetAccNum == currentUser->getAccountNumber()) {
        std::cout << "Cannot transfer to your own account.\n";
        return;
    }

    UserAccount* target = findAccount(targetAccNum);
    if (!target) {
        std::cout << "Target account not found.\n";
        return;
    }

    std::cout << "Enter amount to transfer: ";
    std::cin >> amount;

    if (currentUser->withdraw(amount)) {
        target->deposit(amount);
        saveAccounts();
        std::cout << "Transfer successful! $" << amount << " sent to " << target->getName() << ".\n";
    } else {
        std::cout << "Insufficient funds.\n";
    }
}

void BankSystem::showAllAccounts() {
    std::cout << "All Accounts:\n";
    for (const auto& acc : accounts) {
        acc.display();
    }
}

void BankSystem::run() {
    int choice;
    do {
        std::cout << "\n--- Banking Menu ---\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Login\n";
        if (currentUser) {
            std::cout << "3. Deposit\n";
            std::cout << "4. Withdraw\n";
            std::cout << "5. Transfer\n";
            std::cout << "6. Logout\n";
        }
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: login(); break;
            case 3: if (currentUser) depositToAccount(); break;
            case 4: if (currentUser) withdrawFromAccount(); break;
            case 5: if (currentUser) transferToAnotherAccount(); break;
            case 6: if (currentUser) logout(); break;
            case 0: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid option.\n";
        }
    } while (choice != 0);
}
