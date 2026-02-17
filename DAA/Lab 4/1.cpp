#include<iostream>
using namespace std;
#include<vector>

vector<int> count;

    

    void merge(vector<pair<int,int>>& v, int s, int mid, int e){

        vector<pair<int,int>> temp;

        int i = s;
        int j = mid+1;
        int cnt = 0;

        while(i<=mid && j <= e){
            if(v[i].first > v[j].first){
                cnt++;
                temp.push_back(v[j++]);
            }
            else{
                count[v[i].second] += cnt;
                temp.push_back(v[i++]);
            }
        }

        while(i<=mid){
            count[v[i].second] += cnt;
            temp.push_back(v[i++]);
        }

        while(j<=e){
            temp.push_back(v[j++]);
        }

        for(int i = s; i<= e;i++){
            v[i] = temp[i-s];
        }
    }

    void mergesort(vector<pair<int,int>>& v, int s, int e){

        if( s >= e)
        return;

        int mid = (e+s)/2;

        mergesort(v,s,mid);
        mergesort(v,mid+1,e);

        merge(v,s,mid,e);


    }

    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        count = vector<int> (n,0);

        vector<pair<int,int>> v;

        for(int i = 0;i<n;i++){
            v.push_back({nums[i],i});
        }

        mergesort(v,0,n-1);
        return count;

    }

int main(){

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    vector<int> ans = countSmaller(nums);

    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}