class Solution {
public:
    int reverseDegree(string s) {
        
        int num = 'a' + 26;
        int sum =  0;
        for(int i = 0; s[i] != '\0'; i++){
            int digit = (num - s[i])*(i+1);
            sum += digit; 
        }

        return sum;
    }
};