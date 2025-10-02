#include<stdio.h>

void swap(char *str1, char *str2)

{

char *temp = str1;

str1 = str2;

str2 = temp;

}

int main()

{

char *str1 = "John Forbes";

char *str2 = "Nash Jr";

swap(str1, str2);

printf("%s %s", str1, str2);

return 0;

}       