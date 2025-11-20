#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Product {
    int id;
    string name;
    int qty;
    double price;
};

int main() {

    Product p[5] = {
        {101, "Keyboard", 10, 899.50},
        {102, "Mouse",    25, 499.99},
        {103, "Monitor",   5, 12499.00},
        {104, "USB Cable",50, 149.25},
        {105, "Laptop",    3, 57999.90}
    };

    cout << setfill('-') << setw(44) << "" << endl;
    cout << setfill(' ');   // reset fill

    cout << left << setw(4)  << "ID"
         << left << setw(20) << "Name"
         << right << setw(6) << "Qty"
         << right << setw(10) << "Price" << endl;

    cout << setiosflags(ios::fixed) << setprecision(2);

    for (int i = 0; i < 5; i++) {
        cout << left  << setw(4)  << p[i].id
             << left  << setw(20) << p[i].name
             << right << setw(6)  << p[i].qty
             << right << setw(10) << p[i].price
             << endl;
    }

    cout << resetiosflags(ios::fixed);

    double x;
    cout << "\nEnter a floating value: ";
    cin >> x;

    cout << setiosflags(ios::scientific) << setprecision(4);
    cout << "Scientific: " << x << endl;
    cout << resetiosflags(ios::scientific);

    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "Fixed: " << x << endl;
    cout << resetiosflags(ios::fixed);

    ofstream fout("report.txt");

    fout << setfill('-') << setw(44) << "" << "\n";
    fout << setfill(' ');

    fout << left << setw(4)  << "ID"
         << left << setw(20) << "Name"
         << right << setw(6) << "Qty"
         << right << setw(10) << "Price" << "\n";

    fout << setiosflags(ios::fixed) << setprecision(2);

    for (int i = 0; i < 5; i++) {
        fout << left  << setw(4)  << p[i].id
             << left  << setw(20) << p[i].name
             << right << setw(6)  << p[i].qty
             << right << setw(10) << p[i].price
             << "\n";
    }

    fout.close();
    cout << "\nFormatted table saved to report.txt\n";

    return 0;
}
