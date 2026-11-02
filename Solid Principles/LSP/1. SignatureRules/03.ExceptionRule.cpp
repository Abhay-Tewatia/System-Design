#include <iostream>
#include <stdexcept>
using namespace std;

// Exception Rule:
// A subclass should throw fewer or narrower exceptions
// but not additional or broader exceptions than the parent.
// C++ does not enforce this for ordinary exceptions.

// Exception hierarchy:
//
// std::logic_error
//     |
//     |-- std::invalid_argument
//     |-- std::domain_error
//     |-- std::length_error
//     |-- std::out_of_range
//
// std::runtime_error
//     |
//     |-- std::range_error
//     |-- std::overflow_error
//     |-- std::underflow_error


class Parent {
public:
    virtual void getValue() noexcept(false) {
        // Parent throws logic_error exception
        throw logic_error("Parent error");
    }
};


class Child : public Parent {
public:
    void getValue() noexcept(false) override {
        // Child throws out_of_range exception
        throw out_of_range("Child error");
    }
};


class Client {
private:
    Parent* p;

public:
    Client(Parent* p) {
        this->p = p;
    }

    void takeValue() {
        try {
            p->getValue();
        }
        catch (const logic_error& e) {
            cout << "Logic error exception occurred: "
                 << e.what() << endl;
        }
    }
};


int main() {
    Parent* parent = new Parent();
    Child* child = new Child();

    Client* client = new Client(child);

    client->takeValue();

    return 0;
}