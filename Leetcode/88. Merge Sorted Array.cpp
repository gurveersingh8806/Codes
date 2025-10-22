class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>arr;
        for(int i=0;i<m;i++)
        arr.push_back(nums1[i]);

        int k=0;
        int i=0;
        int j=0;
        while(k<m+n){

            if(i>=m && j<n){
                nums1[k] = nums2[j];
                k++;
                j++;
            }
            else if(i<m && j>=n){
                nums1[k] = arr[i];
                k++;
                i++;
            }
            else if(arr[i]<=nums2[j] && i<m && j<n){
                nums1[k] = arr[i];
                k++;
                i++;
            }
            else{
                nums1[k] = nums2[j];
                k++;
                j++;
            }
        }
    }
};