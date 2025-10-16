#include <stdio.h>

int ways(int k, int n){
    if(k == 0) return 1;
    if(k < 0 || n == 0) return 0;
    return ways(k, n - 1) + ways(k - n, n);
}

int main(){
    int k, n;
    scanf("%d %d", &k, &n);
    printf("%d\n", ways(k, n - 1));
    return 0;
}
