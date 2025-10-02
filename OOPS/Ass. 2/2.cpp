#include <iostream>
using namespace std;

struct Student {
    int roll_no;
    char name[50];
    float marks;
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[100];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of student " << i+1 << endl;
        cout << "Roll No: ";
        cin >> students[i].roll_no;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Marks: ";
        cin >> students[i].marks;
    }

    cout << "Student Details: \n";
    for (int i = 0; i < n; i++) {
        cout << "Roll No: " << students[i].roll_no
            << ", Name: " << students[i].name
            << ", Marks: " << students[i].marks << endl;
    }

    int topper = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].marks > students[topper].marks) {
            topper = i;
        }
    }

    cout << "\nTopper:\n";
    cout << "Roll No: " << students[topper].roll_no
        << ", Name: " << students[topper].name
        << ", Marks: " << students[topper].marks << endl;

    int search_roll, found = 0;
    cout << "\nEnter roll number to search: ";
    cin >> search_roll;

    for (int i = 0; i < n; i++) {
        if (students[i].roll_no == search_roll) {
            cout << "Student found!\n";
            cout << "Roll No: " << students[i].roll_no
                << ", Name: " << students[i].name
                << ", Marks: " << students[i].marks << endl;
            found = 1;
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }

    return 0;
}
