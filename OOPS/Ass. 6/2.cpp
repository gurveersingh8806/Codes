#include <iostream>
using namespace std;

int square(int num) {
    return num * num;
}

int cube(int num) {
    return num * num * num;
}

int increment(int num) {
    return num + 1;
}

int main() {
    int (*operations[3])(int);

    operations[0] = &square;
    operations[1] = &cube;
    operations[2] = &increment;

    int userInput;
    cout << "Enter an integer: ";
    cin >> userInput;
    cout << endl;

    for (int i = 0; i < 3; ++i) {
        int result = operations[i](userInput); 
        switch(i) {
            case 0:
                cout << "Square of " << userInput << " is: " << result << endl;
                break;
            case 1:
                cout << "Cube of " << userInput << " is: " << result << endl;
                break;
            case 2:
                cout << "Increment of " << userInput << " is: " << result << endl;
                break;
        }
    }

    return 0;
}