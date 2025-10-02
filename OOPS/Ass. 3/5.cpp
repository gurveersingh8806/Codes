#include <iostream>
using namespace std;

enum Size { Small = 1, Medium = 2, Large = 3 };

int main() {
    int choice;
    cout << "Enter size (1 = Small, 2 = Medium, 3 = Large): ";
    cin >> choice;

    Size selectedSize = static_cast<Size>(choice);

    int bill = 0;

    switch (selectedSize) {
        case Small:
            bill = 150;
            break;
        case Medium:
            bill = 250;
            break;
        case Large:
            bill = 400;
            break;
        default:
            cout << "Invalid" << endl;
            return 0;
    }

    cout << "Bill amount = " << bill << endl;

    return 0;
}
