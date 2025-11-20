#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    int speed;

public:
    void inputVehicle() {
        cout << "Enter brand: ";
        cin >> brand;
        cout << "Enter speed: ";
        cin >> speed;
    }

    void displayVehicle() const {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle {
protected:
    string fuelType;

public:
    void inputCar() {
        inputVehicle();
        cout << "Enter fuel type: ";
        cin >> fuelType;
    }

    void displayCar() const {
        displayVehicle();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryCapacity;   // in kWh

public:
    void inputElectricCar() {
        inputCar();
        cout << "Enter battery capacity (kWh): ";
        cin >> batteryCapacity;
    }

    void displayElectricCar() const {
        displayCar();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

int main() {
    ElectricCar e;
    e.inputElectricCar();
    e.displayElectricCar();

    return 0;
}
