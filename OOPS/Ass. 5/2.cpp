#include<iostream>
using namespace std;

double area(double radius){
    return 3.14 * radius * radius;
}

double area(double width, double height){
    return width * height;
}

int main(){

    double radius;
    double width,height;
    cout << " Enter radius : ";
    cin >> radius;
    cout << " Enter width and height : ";
    cin >> width >> height;

    cout << "Area of circle :" << area(radius)<< endl;
    cout << "Area of rectangle :"<< area(width,height)<< endl;

    
}