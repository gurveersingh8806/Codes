#include <bits/stdc++.h>
using namespace std;

long long mergeAndCalculate(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    long long sum = 0;
    long long leftSum = 0;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            leftSum += arr[i];   
            temp.push_back(arr[i]);
            i++;
        } 
        else {
            sum += leftSum;      
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (j <= right) {
        sum += leftSum;
        temp.push_back(arr[j]);
        j++;
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }

    return sum;
}

long long mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;
    long long sum = 0;

    sum += mergeSort(arr, left, mid);
    sum += mergeSort(arr, mid + 1, right);
    sum += mergeAndCalculate(arr, left, mid, right);

    return sum;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long result = mergeSort(arr, 0, n - 1);

    cout << "Total sum of smaller previous elements: " << result << endl;
}
