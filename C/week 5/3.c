#include<stdio.h>

int main(){

    int a = 14, b = 8;
    
    a = a^b;
    printf("encryption = %d\n",a);

    a = a^b;
    printf("decryption = %d",a);

    return 0;
}