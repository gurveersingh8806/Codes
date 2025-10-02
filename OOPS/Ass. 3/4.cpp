#include<iostream>
using namespace std;

int main(){

    string deskOwner = "Alice";
    string anotherPerson = "Bob";

    string *const p = &deskOwner;
    *p = "Garry";
    cout << *p << endl;
    //p = &anotherPerson;
}