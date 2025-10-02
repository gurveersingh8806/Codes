#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 1;
    while(i<=n){
        int k=1;
        while(k<=n-i+1){
            cout<<k;
            k++;
        }
        int star = 1;
        while(star<i){
            cout <<"**";
            star++;
        }
        int j =n-i+1;
        while (j){
            cout <<j;
            j--;
        }
        cout << endl;
        i++;
    }
}

