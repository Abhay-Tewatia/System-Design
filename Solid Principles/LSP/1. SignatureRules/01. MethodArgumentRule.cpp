#include<bits/stdc++.h>
using namespace std;

// subtype method arguments can be more general than the supertype method arguments

// c++ imposes this by keeping siganture of the method in the derived class same as that of the base class. This is because if the derived class method has a different signature, it will not override the base class method, leading to unexpected behavior when using polymorphism.

class Parent{
    public:
       virtual void print(string msg){
              cout<<"Parent: "<<msg<<endl;
       }
};

class child: public Parent{
    public:
        void print(string msg) override{
            cout<<"Child: "<<msg<<endl;
        }
};

// client that pass string as msg as client code is written to use the base class method signature

class  client {
private:
    Parent* p;

public:
      client(Parent* p){
        this->p = p;
      }

      void printMsg(string msg){
        p->print(msg);
      }
};

int main(){
    Parent* p = new Parent();
    client c1(p);
    c1.printMsg("Hello from Parent");

    Parent* c = new child();
    client c2(c);
    c2.printMsg("Hello from Child");

    return 0;
}