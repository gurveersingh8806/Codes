#include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    void inputPerson() {
        cout << "Enter name: ";
        cin >> name;
    }
    void displayPerson() const {
        cout << "Name: " << name << endl;
    }
};

class Employee : virtual public Person {
protected:
    double salary;
public:
    void inputEmployee() {
        cout << "Enter salary: ";
        cin >> salary;
    }
    void displayEmployee() const {
        cout << "Salary: " << salary << endl;
    }
};

class Student : virtual public Person {
protected:
    float marks;
public:
    void inputStudent() {
        cout << "Enter marks: ";
        cin >> marks;
    }
    void displayStudent() const {
        cout << "Marks: " << marks << endl;
    }
};

class Manager : public Employee, public Student {
public:
    void inputManager() {
        inputPerson();     
        inputEmployee();
        inputStudent();
    }

    void displayManager() const {
        displayPerson();
        displayEmployee();
        displayStudent();
    }
};

int main() {
    Manager m;
    m.inputManager();
    cout << "\n--- Manager Details ---\n";
    m.displayManager();
    return 0;
}
