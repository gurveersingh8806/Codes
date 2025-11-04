class Solution {
public:

    void merge(vector<int> &arr,int s, int e){

    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *a = new int[len1];
    int *b = new int[len2];

    int k = s;

    for(int i=0;i<len1;i++){
        a[i] = arr[k++];
    }

    k = mid+1;
    for(int i=0;i<len2;i++){
        b[i] = arr[k++];
    }

    int i=0,j=0;
    k=s;

    while(i<len1 && j<len2){
        if(a[i]<b[j])
        arr[k++] = a[i++];
        else
        arr[k++] = b[j++];        
    }

    while(i<len1)
    arr[k++] = a[i++];

    while(j<len2)
    arr[k++] = b[j++];        

    delete []a;
    delete []b;


}

    void mergesort(vector<int> &arr, int s, int e){

    if(s>=e)
    return;

    int mid = s + (e-s)/2;

    mergesort(arr,s,mid);

    mergesort(arr,mid+1,e);

    merge(arr,s,e);


}

    vector<int> sortArray(vector<int>& nums) {

        int s=0;
        int e = nums.size() -1;
        
        mergesort(nums, s,e);

        return nums;
    }
};