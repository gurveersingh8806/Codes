#include <iostream> 
using namespace std;
#include<limits.h>

void solve(int *arr,int n){

    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int i=0;i<n;i++){
        mini = min(mini,arr[i]);
        maxi = max(arr[i],maxi);
    }

    int range = maxi - mini + 1;
    int cnt[range] = {0};

    for(int i=0;i<n;i++){
        cnt[arr[i] - mini]++;
    }

    for(int i=1;i<range;i++){
        cnt[i] += cnt[i-1];
    }

    int ans[n];

    for(int i= n-1; i>= 0; i--){
        int idx = arr[i] - mini;
        ans[cnt[idx] - 1] = arr[i];
        cnt[idx]--;
    }

    for(int i=0;i<n;i++)
    arr[i] = ans[i];
}


int main(){

    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++)
    cin >> arr[i];

    solve(arr,n);

    for(int i : arr)
    cout << i << " ";

    cout << endl;

}