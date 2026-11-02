#include<bits/stdc++.h>
using namespace std;

// class Invarient of a parent class object should not be broken by child class object. In other words, child class should not be able to change the behavior of parent class object. This is called as Class Invarient.

// Hence child class can maintain or strenghthen the invarient of parent class but it should not be able to break the invarient of parent class.

// Invarient: Balance cannot be negative.

class BankAccount {
    protected:
    double balance;

    public:
    BankAccount(double b){
        if(b <0)
        throw invalid_argument("Balance cannot be negative");
        balance = b;
    }

    virtual void withdraw( double amount){
        if(balance - amount <0){
            throw runtime_error("Insufficient funds");
        }
        balance -= amount;
          cout << "Amount withdrawn. Remaining balance is "
             << balance << endl;
    }
};

// Breaks invariant: Should not be allowed.
class CheatAccount : public BankAccount {
public:
    CheatAccount(double b) : BankAccount(b) {}

    void withdraw(double amount) override {
        balance -= amount; // LSP break: Negative balance allowed

        cout << "Amount withdrawn. Remaining balance is "
             << balance << endl;
    }
};

int main() {
    BankAccount* bankAccount = new CheatAccount(100);

    bankAccount->withdraw(150);

    return 0;
}