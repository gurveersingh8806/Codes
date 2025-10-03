class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
        return 1;
        int t=n;
        int digit=0;
        while(t!=0){
            digit = (digit<<1)|1;
            t = t>>1;
        }
        return n^digit;
    }
};