#include <bits/stdc++.h>
using namespace std;

int n, T;
vector<int> a, g;

bool solve(int i, int sum, unordered_set<int> &used) {
    if (sum == T) return true;
    if (i == n || sum > T) return false;

    if (used.find(g[i]) == used.end()) {
        used.insert(g[i]);
        if (solve(i + 1, sum + a[i], used)) return true;
        used.erase(g[i]);
    }

    if (solve(i + 1, sum, used)) return true;

    return false;
}

int main() {
    cin >> n >> T;

    a.resize(n);
    g.resize(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> g[i];

    unordered_set<int> used;

    if (solve(0, 0, used)) cout << "YES\n";
    else cout << "NO\n";
}