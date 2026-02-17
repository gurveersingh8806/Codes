#include<iostream>
using namespace std;
#include<vector>

vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        int m = nums2.size();

        vector<int> temp;
        int i = 0;
        int j = 0;

        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }
            else{
                temp.push_back(nums2[j]);
                j++;
            }
        }

        while(i < n)
        temp.push_back(nums1[i++]);

        while(j < m)
        temp.push_back(nums2[j++]);

        return temp;
        
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans = merge(nums1,nums2);
        int k = ans.size();

        if(k%2 == 0){
            return (ans[k/2 - 1] + ans[k/2])/2.0;
        }
        else
        return (double)ans[k/2];
    }

int main(){

    int n;
    cin >> n;

    vector<int> nums1(n);

    for(int i=0;i<n;i++){
        cin >> nums1[i];
    }

    int m;
    cin >> m;

    vector<int> nums2(m);

    for(int i=0;i<m;i++){
        cin >> nums2[i];
    }

    double ans = findMedianSortedArrays(nums1,nums2);

    cout << "Median : " << ans << endl;
}