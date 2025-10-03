class Solution {
public:
    bool check(int k) {
        while (k > 0) {
            int digit = k % 10;
            k = k / 10;
            if (digit == 0)
                return false;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int a, b;
        vector<int> ans;

        for (int i = 1; i < n; i++) {
            a = i;
            b = n - i;
            if (check(a) && check(b)) {
                ans.push_back(a);
                ans.push_back(b);
                return ans;
            }
        }

        return ans;
    }
};