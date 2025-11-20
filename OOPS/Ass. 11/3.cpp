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

    A* pa = &obj;   
    B* pb = &obj;   

    pa->display();  
    pb->display();  
    return 0;
}
