#include <stdio.h>

int main() {
    char str[100];
    scanf("%s", str);

    int balance = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'r')
            balance++;
        else if (str[i] == 'b')
            balance--;
    }

    if (balance == 0)
        printf("Equal number of r's and b's\n");
    else
        printf("Not equal\n");

    return 0;
}
