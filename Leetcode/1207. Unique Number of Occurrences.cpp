class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        int count;
        vector<int> B;
        vector<int> C;
        int k = 0;

        // Finding unique elements
        for (int i = 0; i < n; i++) {
            int found = 0;
            for (int j = 0; j < k; j++) {
                if (arr[i] == C[j]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                C.push_back(arr[i]);
                k++;
            }
        }

        // Counting occurrences of unique elements
        for (int i = 0; i < k; i++) {
            count = 0;
            for (int j = 0; j < n; j++) {
                if (C[i] == arr[j]) {
                    count++;
                }
            }
            B.push_back(count);
        }

        // Checking for duplicate occurrence counts
        bool g = false;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if (B[i] == B[j]) {
                    g = true;
                    break;
                }
            }
        }

        return !g;
    }
};