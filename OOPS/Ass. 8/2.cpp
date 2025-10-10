#include <iostream>
using namespace std;

class Complex {
    float real, imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    friend istream &operator>>(istream &in, Complex &c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Complex &c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }

    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator*(const Complex &c) {
        return Complex(
            (real * c.real - imag * c.imag),
            (real * c.imag + imag * c.real)
        );
    }
};

int main() {
    Complex c1, c2;
    cout << "Enter first complex number:\n";
    cin >> c1;
    cout << "Enter second complex number:\n";
    cin >> c2;

    Complex sum = c1 + c2;
    Complex product = c1 * c2;

    cout << "\nFirst Complex Number: " << c1;
    cout << "\nSecond Complex Number: " << c2;
    cout << "\n\nSum: " << sum;
    cout << "\nProduct: " << product << endl;

    return 0;
}
