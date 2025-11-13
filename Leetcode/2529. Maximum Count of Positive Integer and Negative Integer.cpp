class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int counta = 0;
        int countb = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0)
            counta++;
            if(nums[i] < 0)
            countb++;
        }

        return max(counta,countb);
    }
};