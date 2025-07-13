# 💸 C++ Banking App

A console-based banking system built in C++ that supports secure account creation, password-protected login, deposits, withdrawals, and fund transfers between users. Built with modular design, file persistence, and extensibility in mind.

---

## 🧰 Features

- 🔐 **Password-Protected Accounts**  
  Accounts are secured with hashed passwords using `std::hash`.

- 💰 **Core Banking Operations**  
  Deposit, withdraw, transfer funds, and check account balances.

- 👤 **User Login Sessions**  
  Only logged-in users can perform transactions or access sensitive info.

- 📁 **File Persistence**  
  All accounts are saved to and loaded from a local `accounts.txt` file.

- 🔄 **Fund Transfers**  
  Send money to other user accounts safely and atomically.

- 🔧 **Modular Object-Oriented Design**  
  Code is split into reusable, maintainable classes:
  - `UserAccount` (account-level logic)
  - `BankSystem` (bank-level logic)
  - `main.cpp` (entry point)

---

## 📂 Project Structure

BankingApp/
├── main.cpp
├── BankSystem.cpp
├── BankSystem.h
├── UserAccount.cpp
├── UserAccount.h
├── accounts.txt # Auto-generated on first run
├── README.md
└── .gitignore