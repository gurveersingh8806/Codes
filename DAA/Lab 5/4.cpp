#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {

    unordered_map<int, int> freq;
    int maxFreq = 0;

    for (int x : nums) {
        freq[x]++;
        maxFreq = max(maxFreq, freq[x]);
    }

    vector<vector<int>> bucket(maxFreq + 1);

    for (auto &p : freq) {
        int num = p.first;
        int f = p.second;
        bucket[f].push_back(num);
    }

    vector<int> ans;

    for (int i = maxFreq; i >= 0 && ans.size() < k; i--) {
        for (int num : bucket[i]) {
            ans.push_back(num);
            if (ans.size() == k)
                return ans;
        }
    }

    return ans;
}

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> result = topKFrequent(nums, k);

    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}
