#include <iostream>
using namespace std;

class Counter {
private:
    static int count;     
    Counter() {          
        count++;
    }

public:
    static Counter* create() {   
        return new Counter();
    }

    static int getCount() {     
        return count;
    }
};

int Counter::count = 0;

int main() {
    Counter* c1 = Counter::create();
    Counter* c2 = Counter::create();
    Counter* c3 = Counter::create();

    cout << "Objects created = " << Counter::getCount() << endl;
    return 0;
}
