#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() {        // virtual → enables runtime polymorphism
        return 0;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() override {        // overriding
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }
};

int main() {
    Shape* ptr;          // base class pointer

    Circle c(5);
    Rectangle r(4, 6);

    ptr = &c;            // pointing to Circle
    cout << "Circle Area = " << ptr->area() << endl;

    ptr = &r;            // pointing to Rectangle
    cout << "Rectangle Area = " << ptr->area() << endl;

    return 0;
}
