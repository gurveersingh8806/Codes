#include<iostream>
using namespace std;
#include<cmath>

int main(){
    int pois;
    cin >> pois;
    int rat[10] = {0};

    for(int i=0;i<10;i++){
        if((pois >> i) & 1){
            rat[i] =1;
        }
    }

    for(int i=0;i<10;i++){
        cout << rat[i] << " ";
    }
    cout << endl;

    int k =0;
    for(int i=0; i<10;i++){
        if(rat[i] == 1){
            k += pow(2,i);
        }
    }

    cout << "The poisoned bottle is bottle no. "<<k<<endl;
}