#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){

    int pivot = arr[s];
    int count = 0;

    for(int i=s+1;i<=e;i++)
        if(arr[i]<=pivot)
            count++;

    int k = s + count;
    swap(arr[s],arr[k]);

    int i = s;
    int j = e;

    while(i<k && j>k){

        while(arr[i]<=arr[k])
        i++;

        while(arr[j]>arr[k])
        j--;

        if(i<k && j>k)
        swap(arr[i++],arr[j--]);

    }
    return k;
}

void quicksort(int arr[], int s, int e){

    if(s>=e)
    return;

    int p = partition(arr,s,e);

    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}

int main (){

    int arr[8] = {34,22,1,27,54,9,9,0};
    int n =8;

    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}