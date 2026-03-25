#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight, value, type;
};

bool cmp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

int main() {
    int N, W, K;
    cout << "Enter number of items: ";
    cin >> N;

    vector<Item> items(N);

    cout << "Enter weight, value and type (0 or 1):\n";
    for (int i = 0; i < N; i++) {
        cin >> items[i].weight >> items[i].value >> items[i].type;
    }

    cout << "Enter capacity W: ";
    cin >> W;

    cout << "Enter max fractional items K: ";
    cin >> K;

    vector<Item> zeroOne, fractional;

    for (auto it : items) {
        if (it.type == 0)
            zeroOne.push_back(it);
        else
            fractional.push_back(it);
    }

    int n = zeroOne.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (zeroOne[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w],zeroOne[i - 1].value +
                            dp[i - 1][w - zeroOne[i - 1].weight]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int maxValue = 0;

    for (int usedW = 0; usedW <= W; usedW++) {
        int value = dp[n][usedW];
        int remaining = W - usedW;

        sort(fractional.begin(), fractional.end(), cmp);

        int count = 0;
        double fracValue = 0;

        for (auto it : fractional) {
            if (count >= K) break;

            if (it.weight <= remaining) {
                remaining -= it.weight;
                fracValue += it.value;
            } else {
                fracValue += ((double)it.value / it.weight) * remaining;
                break;
            }
            count++;
        }

        maxValue = max(maxValue, (int)(value + fracValue));
    }

    cout << "Maximum value = " << maxValue << endl;

    return 0;
}