class Solution {
public:
    bool isPalindrome(int n) {
        int temp = n;
        int digit = 0;
        long int rev = 0;

        while( temp >0 ){

            digit = temp%10;
            rev = rev*10 + digit;
            temp /=10;
        }

        if(rev == n)
        return true;
        else
        return false;
    }
};