
#include <iostream> // Input output ke liye
#include <string> // String data ke liye
using namespace std; // Standard namespace use karne ke liye

class BankAccount { // Parent class create ki
public:
    virtual void deposit(double amount) { // Deposit function banaya
        cout << "Deposited: " << amount << endl; // Deposit message print kiya
    }

    virtual void withdraw(double amount) { // Withdrawal function banaya
        cout << "Withdrawn: " << amount << endl; // Withdrawal message print kiya
    }

    virtual ~BankAccount() {} // Virtual destructor banaya
};

class CurrentAccount : public BankAccount { // CurrentAccount parent ko inherit karta hai
public:
    void withdraw(double amount) override { // Withdrawal implement kiya
        cout << "Current Account: Withdrawn " << amount << endl; // Withdrawal print kiya
    }
};

class SavingsAccount : public BankAccount { // SavingsAccount parent ko inherit karta hai
public:
    void withdraw(double amount) override { // Withdrawal implement kiya
        cout << "Savings Account: Withdrawn " << amount << endl; // Withdrawal print kiya
    }
};

class FixedDepositAccount : public BankAccount { // FixedDeposit parent ko inherit karta hai
public:
    void withdraw(double amount) override { // Withdrawal override kiya
        cout << "Error: Fixed Deposit mein withdrawal allowed nahi hai" << endl; // Error print kiya
    }
};

int main() { // Program execution start hota hai
    CurrentAccount current; // Current account object banaya
    SavingsAccount savings; // Savings account object banaya
    FixedDepositAccount fixed; // Fixed deposit object banaya

    BankAccount* account; // Parent class pointer banaya

    account = &current; // Pointer ko current account par set kiya
    account->withdraw(1000); // Current account se withdrawal kiya

    account = &savings; // Pointer ko savings account par set kiya
    account->withdraw(500); // Savings account se withdrawal kiya

    account = &fixed; // Pointer ko fixed deposit par set kiya
    account->withdraw(2000); // Fixed deposit se withdrawal try kiya

    return 0; // Program end kiya
}
