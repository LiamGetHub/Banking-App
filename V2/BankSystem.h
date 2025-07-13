#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include <vector>
#include "UserAccount.h"

class BankSystem {
private:
    std::vector<UserAccount> accounts;
    int nextAccountNumber;
    UserAccount* currentUser;

    void loadAccounts();
    void saveAccounts() const;
    UserAccount* findAccount(int accountNumber);

public:
    BankSystem();
    void createAccount();
    void login();
    void logout();
    void depositToAccount();
    void withdrawFromAccount();
    void transferToAnotherAccount();
    void showAllAccounts();
    void run();
};

#endif
