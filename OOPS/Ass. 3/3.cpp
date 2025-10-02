#include<iostream>
using namespace std;

int main(){

    string book1 = "C++ Basics"; 
    string book2 = "Advanced Networking";

    string *p = &book1;
    cout << *p << endl;

    p = &book2;
    cout << *p << endl;

    *p = "Hello";
    cout << *p << endl;
}