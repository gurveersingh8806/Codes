#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> solve(vector<int>& nums,int k){

    deque<int>dq;
    vector<int> ans;

    for(int i=0;i<k;i++){
        while(!dq.empty() && nums[dq.back()] <= nums[i])
        dq.pop_back();

        dq.push_back(i);
    }

    ans.push_back(nums[dq.front()]);

    for(int i = k;i<nums.size();i++){

        if(!dq.empty() && i - dq.front() > k)
        dq.pop_front();


        while(!dq.empty() && nums[dq.back()] <= nums[i])
        dq.pop_back();

        dq.push_back(i);
    

        ans.push_back(nums[dq.front()]);

    }

    return ans;


}


int main(){

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> ans = solve(nums,k);
    for(auto i : ans)
    cout << i << " ";
    cout << endl;
}