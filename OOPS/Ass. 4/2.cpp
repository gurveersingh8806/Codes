#include <iostream>
using namespace std;

class Complex {
public:
    float real, imag;

    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    Complex add(Complex c) {
        Complex result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }

    Complex subtract(Complex c) {
        Complex result;
        result.real = real - c.real;
        result.imag = imag - c.imag;
        return result;
    }

    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    Complex c1, c2, sum, diff;

    cout << "Enter first complex number:\n";
    c1.input();

    cout << "Enter second complex number:\n";
    c2.input();

    sum = c1.add(c2);
    diff = c1.subtract(c2);

    cout << "\nFirst number: ";
    c1.display();

    cout << "Second number: ";
    c2.display();

    cout << "Sum: ";
    sum.display();

    cout << "Difference: ";
    diff.display();

    return 0;
}
