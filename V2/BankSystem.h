#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include <vector>
#include "UserAccount.h"

class BankSystem {
private:
    std::vector<UserAccount> accounts;
    int nextAccountNumber;

    void loadAccounts();
    void saveAccounts() const;

    UserAccount* findAccount(int accountNumber);

public:
    BankSystem();
    void createAccount();
    void depositToAccount();
    void withdrawFromAccount();
    void showAllAccounts();
    void run();
};

#endif
