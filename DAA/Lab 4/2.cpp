#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    long long count = 0;
    int j = mid + 1;

    for (int i = left; i <= mid; i++) {
        while (j <= right && (long long)arr[i] > 2LL * arr[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    vector<int> temp;
    int i = left, k = mid + 1;

    while (i <= mid && k <= right) {
        if (arr[i] <= arr[k])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[k++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (k <= right) temp.push_back(arr[k++]);

    for (int p = 0; p < temp.size(); p++) {
        arr[left + p] = temp[p];
    }

    return count;
}

long long mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;
    long long count = 0;

    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid + 1, right);
    count += mergeAndCount(arr, left, mid, right);

    return count;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long result = mergeSort(arr, 0, n - 1);

    cout << "Number of valid pairs: " << result << endl;

    return 0;
}
