#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> A(n);
    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        mp[A[i]].push_back(i);
    }

    int q;
    cin >> q;

    while (q--) {
        int L, R, x;
        cin >> L >> R >> x;

        if (mp.find(x) == mp.end()) {
            cout << 0 << "\n";
            continue;
        }

        vector<int>& pos = mp[x];

        int count = upper_bound(pos.begin(), pos.end(), R)
                  - lower_bound(pos.begin(), pos.end(), L);

        cout << count << "\n";
    }

    return 0;
}
