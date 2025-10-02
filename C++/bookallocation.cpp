#include<iostream>
using namespace std;


bool possi(int arr[],int size,int n, int mid){

    int sum1 =0;
    int count =1;
    for(int i=0;i<size;i++){
        sum1 +=arr[i];
        if(sum1>mid){
            count ++;
            if(count > n || arr[i] > mid)
            return false;

            sum1 = arr[i];
        }

    }
    return true;

}


int bookallo(int arr[],int size, int n){

    int s=0;
    int sum =0;

    for(int i=0;i<size;i++)
    sum +=arr[i];

    int e = sum;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){

        if (possi(arr,size,n,mid)){
            ans = mid;
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }

        mid = s + (e-s)/2;
        

    }

    
    return ans;
}


int main(){

    int arr[] = {10,20,30,40};

    int min = bookallo(arr,4,2);

    cout << "min is " << min << endl;

}






