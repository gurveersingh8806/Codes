#include <iostream> 
using namespace std;
#include<cmath>

void solve(int arr[],int exp,int n){

    int cnt[10] = {0};

    int ans[n];

    for(int i=0;i<n;i++){
        int digit = (arr[i]/exp)%10;
        cnt[digit]++;
    }

    for(int i=1;i<10;i++)
    cnt[i] += cnt[i-1];

    for(int i = n-1; i >= 0; i--){
        int digit  = (arr[i]/exp)%10;
        ans[cnt[digit]-1] = arr[i];
        cnt[digit]-- ;
    }

    for(int i=0;i<n;i++)
    arr[i] = ans[i];

}



void radixsort(int arr[],int n, int digits){

    int exp = 1;

    for(int i = 0; i< digits;i++){
        solve(arr,exp,n);
        exp *= 10;
    }
}


int main(){

    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++)
    cin >> arr[i];

    int digits = 3;

    radixsort(arr,n,digits);

    for(int i : arr)
    cout << i << " ";

    cout << endl;

}