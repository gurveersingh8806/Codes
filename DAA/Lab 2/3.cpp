#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>freq;

        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        priority_queue<pair<int,int>> q;

        for(auto i : freq){
            q.push({i.second,i.first});
        }
        vector<int>ans;

        while(k>0){
            auto temp = q.top();
            q.pop();

            ans.push_back(temp.second);
            k--;

        }
        return ans;

    }

int main(){

    vector<int> nums = {1,2,1,2,1,2,3,1,3,2};
    int k = 2;

    vector<int> ans = topKFrequent(nums,k);

    for(auto i : ans)
    cout << i << " ";

    cout << endl;
}