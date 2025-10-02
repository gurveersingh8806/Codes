#include <iostream>
using namespace std;

class DB; 

class DM {
    float meters;
    float centimeters;
public:
    DM(float m = 0, float cm = 0) {
        meters = m;
        centimeters = cm;
    }

    void input() {
        cout << "Enter distance in meters and centimeters: ";
        cin >> meters >> centimeters;
    }

    void display() {
        cout << meters << " meters " << centimeters << " centimeters\n";
    }

    friend DM add(DM, DB);
};

class DB {
    float feet;
    float inches;
public:
    DB(float f = 0, float in = 0) {
        feet = f;
        inches = in;
    }

    void input() {
        cout << "Enter distance in feet and inches: ";
        cin >> feet >> inches;
    }

    void display() {
        cout << feet << " feet " << inches << " inches\n";
    }

    friend DM add(DM, DB); 
};

DM add(DM d1, DB d2) {
    float d1_cm = d1.meters * 100 + d1.centimeters;
    float d2_cm = (d2.feet * 12 + d2.inches) * 2.54;

    float total_cm = d1_cm + d2_cm;

    DM temp;
    temp.meters = (int)(total_cm / 100);
    temp.centimeters = (int)(total_cm) % 100;

    return temp;
}

int main() {
    DM d1, result;
    DB d2;

    d1.input();
    d2.input();

    result = add(d1, d2);

    cout << "\nResult in meters and centimeters:\n";
    result.display();

    return 0;
}
