#include <iostream>
using namespace std;

class A {
public:
    virtual void display() {
        cout << "Display from class A" << endl;
    }
};

class B {
public:
    virtual void display() {
        cout << "Display from class B" << endl;
    }
};

class C : public A, public B {
public:
    void display() override {
        cout << "Display from class C" << endl;
    }
};

int main() {
    C obj;

    A* pa = &obj;   // pointer of base class A
    B* pb = &obj;   // pointer of base class B

    pa->display();  // calls C::display()
    pb->display();  // calls C::display()

    return 0;
}
