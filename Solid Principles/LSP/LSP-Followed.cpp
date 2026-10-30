
#include <iostream> // Input output ke liye
using namespace std; // Standard namespace use karne ke liye

class BankAccount { // Common parent class banayi
public:
    virtual void deposit(double amount) { // Common deposit function banaya
        cout << "Deposited: " << amount << endl; // Deposit message print kiya
    }

    virtual ~BankAccount() {} // Virtual destructor banaya
};

class WithdrawableAccount : public BankAccount { // Withdrawable accounts ki abstract class banayi
public:
    virtual void withdraw(double amount) = 0; // Withdrawal ka contract banaya
};

class CurrentAccount : public WithdrawableAccount { // Current account withdrawal support karta hai
public:
    void withdraw(double amount) override { // Withdrawal implement kiya
        cout << "Current Account: Withdrawn " << amount << endl; // Withdrawal print kiya
    }
};

class SavingsAccount : public WithdrawableAccount { // Savings account withdrawal support karta hai
public:
    void withdraw(double amount) override { // Withdrawal implement kiya
        cout << "Savings Account: Withdrawn " << amount << endl; // Withdrawal print kiya
    }
};

class FixedDepositAccount : public BankAccount { // Fixed deposit sirf BankAccount ko inherit karta hai
public:
    void deposit(double amount) override { // Deposit function implement kiya
        cout << "Fixed Deposit: Deposited " << amount << endl; // Deposit print kiya
    }
};

void withdrawMoney(WithdrawableAccount& account) { // Sirf withdrawable account accept karta hai
    account.withdraw(1000); // Account se withdrawal karta hai
}

int main() { // Program execution start hota hai
    CurrentAccount current; // Current account object banaya
    SavingsAccount savings; // Savings account object banaya
    FixedDepositAccount fixed; // Fixed deposit object banaya

    current.deposit(5000); // Current account mein deposit kiya
    savings.deposit(3000); // Savings account mein deposit kiya
    fixed.deposit(10000); // Fixed deposit mein deposit kiya

    withdrawMoney(current); // Current account se withdrawal kiya
    withdrawMoney(savings); // Savings account se withdrawal kiya

    // withdrawMoney(fixed); // Ye compile nahi hoga, kyunki FixedDeposit withdrawable nahi hai

    return 0; // Program end kiya
}
