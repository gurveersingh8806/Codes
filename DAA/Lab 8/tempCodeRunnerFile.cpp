#include <bits/stdc++.h>
using namespace std;

long long matrixChain(vector<int> &p) {
    int n = p.size() - 1;

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++) {
                long long cost = dp[i][k] + dp[k + 1][j]
                               + 1LL * p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);
    cout << "Enter dimensions array (size " << n + 1 << "): ";
    for (int i = 0; i <= n; i++){
        cin >> p[i];
    }

    long long ans = matrixChain(p);

    for (int i = 1; i < n; i++) {

        if (p[i - 1] == p[i + 1]) {

            vector<int> temp = p;

            swap(temp[i], temp[i + 1]);

            long long newCost = matrixChain(temp);

            ans = min(ans, newCost);
        }
    }

    cout << "\nMinimum scalar multiplications: " << ans << "\n";

    return 0;
}