#include<iostream>
using namespace std;

class space{
    public:

    int x;
    int y;
    friend space operator+(space &obj1,space &obj2){
        space c;
        c.x = obj1.x + obj2.x;
        c.y = obj1.y + obj2.y;
        return c;
    }
};
class disco : public space{
public:
    int s;
};

int main(){
    space a,b;
    a.x = 5;
    b.x = 4;
    a.y = -2;
    b.y = 6;

    int space :: *ptr1 = &space :: x;
    int space :: *ptr2 = &space :: y;

    a.*ptr1 = 44;
    b.*ptr2 = 45;
    space c = a + b;


    
    cout << c.x << "  " << c.y ;
}