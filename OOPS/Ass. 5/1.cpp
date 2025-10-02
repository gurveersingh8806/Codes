#include<iostream>
using namespace std;

double power(double m,int n=2){
    double ans = 1;
    for(int i=1;i<=n;i++){
        ans = ans*m;
    }
    return ans;
}

int main(){

    double m;
    int n;
    cout << "Enter values for m and n:"<< endl;
    cin >> m >> n;

    cout << power(m,n)<< endl;


}