#include<stdio.h>

int main(){

    int n=0,e=0,s=0,w=0;
    int t;
    printf("enter the number of times you want to move the traffic:\n");
    scanf("%d",&t);
    int q=t;
    printf("enter the number of vehicles in the N,E,S,W directions respectively:\n");

    while(t){
        int n1,e1,s1,w1;
        scanf("%d%d%d%d",&n1,&e1,&s1,&w1);
        printf("total no. of vehicles in the N,E,S,W direction are :\n N=%d\t E=%d\t S=%d\t W=%d\n ",(n+n1),(e+e1),(s+s1),(w+w1));
        
        switch(1){
        case 1:     if((n+n1)>(e+e1) && (n+n1)>(s+s1) && (n+n1)>(w+w1)){
                    printf("south is set to green\n");
                    n=0;
                    n1=0;
                    break;}
        case 2:     if((e+e1)>(n+n1) && (e+e1)>(s+s1) && (e+e1)>(w+w1)){
                    printf("west is set to green\n");
                    e=0;
                    e1=0;
                    break;}
        case 3:     if((s+s1)>(n+n1) && (s+s1)>(e+e1) && (s+s1)>(w+w1)){
                    printf("north is set to green\n");
                    s=0;
                    s1=0;
                    break;}
        case 4:     if((w+w1)>(e+e1) && (w+w1)>(s+s1) && (w+w1)>(n+n1)){
                    printf("east is set to green\n");
                    w=0;
                    w1=0;
                    break;}
        }
        n = n+n1;
        e = e+e1;
        w = w+w1;
        s = s+s1;
        t--;
}
    printf("The traffic lights have been changed %d times.\n", q);
    return 0;
}