class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int j = nums.size()-1;

        while(i<nums.size() && j>=0 && i<j){
            if(nums[i] == val && nums[j]!= val){
            swap(nums[i],nums[j]);
            i++;
            j--;}
            if(nums[i]!=val)
            i++;
            if(nums[j]==val)
            j--;
        }

        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == val)
            break;

            k++;

            
        }

        return k;
    }
};