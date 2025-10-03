class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flag = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != nums[0])
                return 1;
        }
            return 0;
    
    }
};