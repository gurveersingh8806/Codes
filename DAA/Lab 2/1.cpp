#include<iostream>
using namespace std;

int findMaxAverage(int nums[], int n, int k) {
        
        int i= 0;
        int j = k-1;
        int ans = 0;

        if(n <= 1)
        return nums[0];

        for(int s=i;s<=j;s++){
            ans += nums[s];
        }
        int sum=ans;

        while(j<n-1){
            
            sum = sum + nums[j+1] - nums[i];
            ans = max(ans,sum);
            i++;
            j++;
        }
        
        return ans;

    }


    int main(){

        int nums[6] = {1,12,-5,-6,50,3};
        int k = 4;
        int n = sizeof(nums)/sizeof(nums[0]);

        cout << "maximum sum subarray : "  << findMaxAverage(nums,n,k)<< endl;
    }