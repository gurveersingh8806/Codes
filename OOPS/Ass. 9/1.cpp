#include <iostream>
using namespace std;

class Counter {
private:
    static int count;     // stores how many objects created
    Counter() {           // private constructor
        count++;
    }

public:
    static Counter* create() {   // creates object + increments count
        return new Counter();
    }

    static int getCount() {      // returns how many objects created
        return count;
    }
};

// initialize static variable
int Counter::count = 0;

int main() {
    Counter* c1 = Counter::create();
    Counter* c2 = Counter::create();
    Counter* c3 = Counter::create();

    cout << "Objects created = " << Counter::getCount() << endl;
    return 0;
}
