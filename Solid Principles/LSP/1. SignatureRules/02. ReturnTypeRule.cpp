#include<bits/stdc++.h>
using namespace std;

// Return type Rule:
// Subtype overriden method return type should be  either identical or narrower thent he parent method's return type. 
// This is because if the derived class method has a different return type, it will not override the base class method, leading to unexpected behavior when using polymorphism.

class Animal{
    // some common Animal properties and methods
};

class Dog: public Animal{
    // some Dog specific properties and methods
};

class Parent{
    public:
    virtual Animal* getAnimal(){
        cout <<"Parent: Returning Animal" << endl;
        return new Animal();
    }
};
class Child: public Parent{
    public:
    Dog* getAnimal() override{
        cout <<"Child: Returning Dog" << endl;
        return new Dog();
    }
};

class client {
private:
    Parent* p;

    public:
    client(Parent* p){
        this->p = p;
    }
    void takeAnimal(){
        Animal* a = p->getAnimal();
        // do something with the animal
    }
};

int main(){
    Parent* p = new Parent();
    client c1(p);
    c1.takeAnimal();

    Parent* c = new Child();
    client c2(c);
    c2.takeAnimal();

    return 0;
}