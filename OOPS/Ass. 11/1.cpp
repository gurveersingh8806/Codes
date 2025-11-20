#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() {        
        return 0;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() override {        
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
    Shape* ptr;         

    Circle c(5);
    Rectangle r(4, 6);

    ptr = &c;           
    cout << "Circle Area = " << ptr->area() << endl;

    ptr = &r;           
    cout << "Rectangle Area = " << ptr->area() << endl;

    return 0;
}
