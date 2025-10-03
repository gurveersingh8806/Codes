class Solution {
public:
    bool isPalindrome(string s) {
        
        string a;
        for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
        }
        for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))  {
            a.push_back(s[i]);
        }
        }
        string b = a;
        int n = a.size();
        for(int i=0;i<n;i++){
            b[i] = a[n-i-1];
        }

        if(b == a)
        return true;

        else
        return false;

    }
};