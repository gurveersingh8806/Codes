#include <stdio.h>

int main(){

    int age=19,year=10,y=3,x=5,z=4,w=2,c=2;
    float length = 1.4;

    (age>=18 && age<=21)?printf("yes1\n"):printf("no1\n");

    (length<1.5 && length>0.1)?printf("yes2\n"):printf("no2\n");

    (year%4==0)?printf("yes3\n"):printf("no3\n");

    (y>x<z)?printf("yes4\n"):printf("no4\n");

    (w == c | w > 3)?printf("yes5"):printf("no5");



    return 0;
}