#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // a. Overload + as member
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // a. Overload - as member
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // b. Overload * as friend
    friend Complex operator*(const Complex& a, const Complex& b);

    // c. Overload << to print a + bi or a - bi
    friend ostream& operator<<(ostream& out, const Complex& c);
};

// * operator as friend
Complex operator*(const Complex& a, const Complex& b) {
    return Complex(
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    );
}

// << operator
ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real;

    if (c.imag >= 0)
        out << " + " << c.imag << "i";
    else
        out << " - " << -c.imag << "i";

    return out;
}

int main() {
    Complex a(3, 4);
    Complex b(1, -2);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;

    return 0;
}
