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

// Employee and Student inherit Person virtually
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

class WorkingStudent : public Employee, public Student {
public:
    void inputWorkingStudent() {
        inputPerson();       // only one Person due to virtual inheritance
        inputEmployee();
        inputStudent();
    }

    void displayWorkingStudent() const {
        displayPerson();
        displayEmployee();
        displayStudent();
    }
};

int main() {
    WorkingStudent ws;

    ws.inputWorkingStudent();
    ws.displayWorkingStudent();

    return 0;
}
