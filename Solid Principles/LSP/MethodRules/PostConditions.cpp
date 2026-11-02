#include<bits/stdc++.h>
using namespace std;

// A Postcondition must be statisfied after a method is executed.

// Sub classes can strengthen the Postcondition but cannot weaken it.

class Car{
protected:
    int speed;
public:
   Car() {
       speed = 0;
   }
// Speed increase karne ka method
   void accelerate(){
    cout << "Accelerating" << endl;
    speed += 20;
   }

    //PostCondition: Speed must reduce after brake
    virtual void brake(){
        cout << "Applying breaks" << endl;
        speed -= 20;
    }
    // Speed display karne ka method
    void showSpeed() {
        cout << "Current Speed: " << speed << endl;
    }
   
};

// Subclass can strengthen postcondition - Does not violate LSP
class HybridCar : public Car{
private:
    int charge;

public:
    
    HybridCar() : Car() {
        charge = 0;
    }

    // PostCondition : speed must reduce after brake
    // PostCondition : Charge must increase

    void brake() {
        cout << "Applying brakes" << endl;
        speed -= 20;
        charge += 10;

    }
    // charge display karne ka method
    void showCharge(){
        cout << "Battery Charge : "<< charge << endl;
    }
};

// main function
int main(){
    Car c1;

    cout << "----- Normal Car ----"<<endl;

    c1.accelerate();
    c1.showSpeed();

    c1.brake();
    c1.showSpeed();


    // Child class ka object
    HybridCar h1;

    cout << "\n----- Hybrid Car -----" << endl;

    h1.accelerate();
    h1.showSpeed();

    h1.brake();
    h1.showSpeed();
    h1.showCharge();

    return 0;
}
