#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {     // try removing 'virtual' to see the difference
        cout << "Base destructor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived destructor\n";
    }
};

int main() {
    Base* arr[3];

    arr[0] = new Derived();
    arr[1] = new Derived();
    arr[2] = new Derived();

    // Delete only some objects
    delete arr[0];
    delete arr[2];

    cout << "Not deleting arr[1]\n";

    return 0;
}
