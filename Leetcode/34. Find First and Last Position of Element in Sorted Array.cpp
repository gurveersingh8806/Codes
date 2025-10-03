class Solution {
public:


    vector<int> find(vector<int>& arr, int size, int k){

    int s=0;
    int e= size-1;
    int mid = s + (e-s)/2;
    vector<int> a = {-1,-1};

    while(s<=e){
        int mid = s + (e-s)/2;

        if(arr[mid] == k){
            a[0] = mid;
            e = mid-1;
        }

        else if(k>arr[mid])
        s = mid+1;

        else
        e = mid-1;

    }

    s=0;
    e=size-1;

    while(s<=e){
        int mid = s + (e-s)/2;

        if(arr[mid] == k){
            a[1] = mid;
            s = mid + 1;
        }

        else if(k>arr[mid])
        s = mid+1;

        else
        e = mid-1;

    }

    return a;
}
    vector<int> searchRange(vector<int>& arr, int k) {

        return find(arr,arr.size(),k);
        
    }
};