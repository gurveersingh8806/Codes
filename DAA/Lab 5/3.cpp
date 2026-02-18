#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& nums, long long exp) {

    int n = nums.size();

    vector<int> cnt(10, 0);
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        int digit = (nums[i] / exp) % 10;
        cnt[digit]++;
    }

    for (int i = 1; i < 10; i++)
        cnt[i] += cnt[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (nums[i] / exp) % 10;
        ans[cnt[digit] - 1] = nums[i];
        cnt[digit]--;
    }

    nums = ans;
}

int maximumGap(vector<int>& nums) {

    int n = nums.size();
    if (n < 2) return 0;

    int maxi = *max_element(nums.begin(), nums.end());

    for (long long exp = 1; maxi / exp > 0; exp *= 10) {
        countingSort(nums, exp);
    }

    int diff = 0;

    for (int i = 1; i < n; i++) {
        diff = max(diff, nums[i] - nums[i - 1]);
    }

    return diff;
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int ans = maximumGap(nums);

    cout << ans << endl;

    return 0;
}
