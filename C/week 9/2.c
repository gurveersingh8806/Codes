#include<stdio.h>

int main(){

    int n,a;
    printf("enter your DOB in MMDDYYYY format:\n");
    scanf("%d",&n);
    
    int d = n;
    d = d/10000;
    d = d%100;

    int m = n;
    m = m/1000000;

    int y = n;
    y = y%10000;

    int ly;
    if(((y%4==0) && (y%100 !=0)) || (y%400==0))
    ly = y;
    else 
    ly=0;

    (a=(((d<=31) && (m==1 || m== 3 || m==5 || m==7 || m==8 || m== 10 || m==12)) || 
    ((d<=30) && (m==4 || m==6 || m==9 || m==11)) || 
    ((ly!=0) && (d<=29)) || ((ly==0) && (d<=28))))?
    printf("date = %d\n", d):0;


    m==1?printf("month = January\n"):m==2?printf("month = February\n"):
    m==3?printf("month = March\n"):m==4?printf("month = April\n"):
    m==5?printf("month = May\n"):m==6?printf("month = June\n"):
    m==7?printf("month = July\n"):m==8?printf("month = August\n"):
    m==9?printf("month = September\n"):m==10?printf("month = October\n"):
    m==11?printf("month = November\n"):m==12?printf("month = December\n"):0;


    (ly==y)?printf("year = %d\n", ly): printf("year is %d\n", y);

    return 0;
}