class Solution {
public:
    int fibbonaci(int k){
        if (k == 0)
        return 0;
        if ( k == 1)
        return 1;

        return fibbonaci(k-1) + fibbonaci(k-2);
    }

    int fib(int n) {

        return fibbonaci(n);
        
    }
};