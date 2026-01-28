#include<iostream>
using namespace std;

class student{

    public:
    int rollNo;
    int marks;

    void display(){
        cout << "roll no. - "<<rollNo<< endl;
        cout << "marks - " << marks << endl;
    }
    friend student getdata(student&);
};

student getdata(student& s){
    student s1;
    s1.rollNo = s.rollNo;
    s1.marks = s.marks;
    return s1;
}

class ExaminationCommittee {

    friend student getdata(student&);
    public :

    void applyModeration(student&s , int delta){
        s.marks = s.marks + delta;
    }

};

int main(){
    student a;
    a.rollNo = 10;
    a.marks  = 78;

    student b = getdata(a);

    ExaminationCommittee e;
    cout << "original marks :- "<< endl;
    b.display();
    e.applyModeration(b,5);
    cout << "moderated marks :- " << endl;
    b.display();


}

