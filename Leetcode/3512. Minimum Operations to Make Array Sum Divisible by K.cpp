class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int sum = nums[0];
        for(int i=1;i<nums.size();i++){
            sum += nums[i];
        }

        int remainder = sum%k;
        if(remainder == 0)
        return 0;


        int i=0;
        int operations=0;
            while(remainder >0){

             if(nums[i]>0){
                remainder--;
                nums[i]--;
                operations++;
             }
             else{
                i++;
             if(nums[i]>0){
                remainder--;
                nums[i]--;
                operations++;
             }
             }
            }

        return operations;

    }
};