class Solution {
public:
    int reverse(int x) {
        int n = x; // Assign the input x to n
        int digit;
        int result = 0; // Initialize result to store the reversed number

        // Reverse the number
        while (n != 0) {
            digit = n % 10;
            // Check for overflow before adding the digit
            if (result > INT32_MAX / 10 || (result == INT32_MAX / 10 && digit > 7)) {
                return 0;
            }
            if (result < INT32_MIN / 10 || (result == INT32_MIN / 10 && digit < -8)) {
                return 0;
            }
            result = result * 10 + digit;
            n = n / 10;
        }

        return result;
    }
};
