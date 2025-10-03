class Solution {
public:

    int pivot(vector<int>& arr,int size){

        int s = 0;
        int e = size-1;

        while(s<e){
            int mid = s + (e-s)/2;

            if(arr[e]< arr[mid] )
            s = mid+1;
            else
            e = mid;
        }

        return s;


    }

    int binary(vector<int>& arr,int s, int e, int k){
        int mid = s + (e-s)/2;

        while(s<=e){
            mid = s + (e-s)/2;

            if(k == arr[mid])
            return mid;

            else if (k>arr[mid])
            s= mid+1;

            else
            e = mid-1;

        }

        return -1;

    }

    int find(vector<int>& arr, int size, int k){

        int p = pivot(arr,size);

        if(k>=arr[p] && k<=arr[size-1])
        return binary(arr,p,size-1,k);

        else
        return binary(arr,0,p-1,k);
    }

    int search(vector<int>& arr, int target) {

        return find(arr,arr.size(),target);
        
    }
};