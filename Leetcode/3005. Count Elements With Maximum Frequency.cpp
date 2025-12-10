
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>p;
        for(int i=0;i<nums.size();i++){
            p[nums[i]]++;
        }
        int maxi = INT_MIN;

        
        for(auto i:p){
            if(i.second > maxi){
                maxi = i.second;
            }
        }
        int count = 0;
        for(auto j:p){
            if(j.second == maxi){
                count += j.second;
            }
        }
        return count;
    }
};