#include<stdio.h>

void findtarget(int nums[],int target,int n,int ans[],int flag[]){
    for(int i=0;i<n;i++){
        if(flag[i]==1)
        continue;
        else{
            flag[i] = 1;
            for(int j = i+1;j<n;j++){
                if(flag[j]==0){
                    if(nums[i] + nums[j] == target){
                        ans[i] = j;
                        flag[j] = 1;
                    }
                }
            }
        }
    }
}

int main(){
    int nums[] = {2,3,1,4,5,9};
    int target = 7;
    int n = sizeof(nums)/sizeof(nums[0]);
    int ans[1000] = {0};
    int flag[1000] = {0};
    findtarget(nums,target,n,ans,flag);

    for(int i=0;i<1000;i++){
        if(ans[i]!=0){
            printf("%d %d\n",i,ans[i]);

        }
    }
}