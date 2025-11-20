#include <iostream>
using namespace std;

class Vehicle {             // Abstract class
public:
    virtual void startEngine() = 0;   // Pure virtual function
};

class Car : public Vehicle {
public:
    void startEngine() override {
        cout << "Car engine started." << endl;
    }
};

class Bike : public Vehicle {
public:
    void startEngine() override {
        cout << "Bike engine started." << endl;
    }
};

int main() {
    Vehicle* v;

    Car c;
    Bike b;

    v = &c;
    v->startEngine();       // calls Car's implementation

    v = &b;
    v->startEngine();       // calls Bike's implementation

    return 0;
}
