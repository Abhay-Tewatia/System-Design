#include <bits/stdc++.h>
using namespace std;

// A Precondition must be satisfied before a method executes.

// Child classes can weaken the precondition
// but cannot strengthen it.

// Parent class
class User {
public:

    // Precondition: Password must be at least 8 characters long
    virtual void setPassword(string password) {

        if (password.length() < 8) {
            throw invalid_argument("Password must be at least 8 characters long!");
        }

        cout << "Password set successfully" << endl;
    }
};

// Child class
class AdminUser : public User {
public:

    // Precondition: Password must be at least 6 characters long
    // Child class weakens the precondition
    void setPassword(string password) override {

        if (password.length() < 6) {
            throw invalid_argument("Password must be at least 6 characters long!");
        }

        cout << "Password set successfully" << endl;
    }
};

// Main function
int main() {

    // Parent class pointer pointing to child class object
    User* user = new AdminUser();

    // AdminUser allows shorter passwords
    user->setPassword("Admin1");

    delete user;

    return 0;
}