#include <iostream>
using namespace std;

struct Student {
    string name;
    int roll_no;
    float marks;
};

int main() {
    Student s;

    cout << "Enter student name: ";
    getline(cin, s.name);

    cout << "Enter roll number: ";
    cin >> s.roll_no;

    cout << "Enter marks: ";
    cin >> s.marks;

    cout << "Student Details :" << endl;
    cout << "Name      : " << s.name << endl;
    cout << "Roll No   : " << s.roll_no << endl;
    cout << "Marks     : " << s.marks << endl;

    return 0;
}