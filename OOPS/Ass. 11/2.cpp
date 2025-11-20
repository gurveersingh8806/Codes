#include <iostream>
using namespace std;

class Vehicle {            
public:
    virtual void startEngine() = 0;  
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
    v->startEngine();       

    v = &b;
    v->startEngine();      

    return 0;
}
