#include<iostream>
using namespace std;

class expense{
    public:
    string name;
    int units;

};

float bill_count(int units){
    float bill=0;
    if(units<=100)
    bill = 0.4 * units;
    else if(units > 100 && units <= 300){
        bill = 0.5*(units-100) + 0.4*100;
    }
    else if(units>300){
        bill = (units-300)*0.6 + 0.5*200 + 0.4*100;
    }

    if(bill < 150)
    return 150;

    if(bill > 250)
    return bill + bill*0.15;

    return bill;
}

int main(){

    expense user1;
    cout << "Enter name of user1 : ";
    cin >> user1.name;
    cout << "Enter no. of units for user 1: ";
    cin >> user1.units;

    expense user2;
    cout << "Enter name of user2 : ";
    cin >> user2.name;
    cout << "Enter no. of units for user 2: ";
    cin >> user2.units;

    expense user3;
    cout << "Enter name of user3 : ";
    cin >> user3.name;
    cout << "Enter no. of units for user 3: ";
    cin >> user3.units;

    float bill1 = bill_count(user1.units);
    float bill2 = bill_count(user2.units);
    float bill3 = bill_count(user3.units);

        cout << "Total bill for "<< user1.name << " is : "<< bill1 << endl;
        cout << "Total bill for "<< user2.name << " is : "<< bill2 << endl;
        cout << "Total bill for "<< user3.name << " is : "<< bill3 << endl;


}