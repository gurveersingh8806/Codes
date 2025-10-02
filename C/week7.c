#include<stdio.h>
#include<stdlib.h>

int main(){

    int n;
    int b1=0,b2=0,over=0,runs=0, ball=0, strike=0,extra = 0;
    printf("enter the runs scored on each ball as: \n 0 to 6 for each run,\n 7 for no ball, \n 8 for wide ball \n 9 for LB \n -1 for out\n");
    while(ball<12){
        printf("enter runs scored on ball %d\n",ball+1);
        scanf("%d",&n);
        switch(n){
            case 0: {ball++;
                break;}
            case 1:{ if(strike%2==0)
                    b1 += 1;
                    else
                    b2 += 1;
                    runs += 1;
                    strike ++;
                    ball ++;
                    break;}
            case 2 : { if(strike%2==0)
                b1 += 2;
                else
                b2 += 2;
                runs += 2;
                ball ++;
                break;}
            case 3 : { if(strike%2==0)
                b1 += 3;
                else
                b2 += 3;
                runs += 3;
                strike ++;
                ball ++;
                break;}
            case 4 :  { if(strike%2==0)
                b1 += 4;
                else
                b2 += 4;
                runs += 4;
                ball ++;
                break;}
            case 5 :  { if(strike%2==0)
                b1 += 5;
                else
                b2 += 5;
                runs += 5;
                strike ++;
                ball ++;
                break;}
            case 6 :  { if(strike%2==0)
                b1 += 6;
                else
                b2 += 6;
                runs += 6;
                ball ++;
                break;}
            case 7 :{ extra += 1;
            runs+=1;
            int i;
            printf("what was scored at the no ball?\n");
            scanf("%d",&i);
            if(strike%2==0)
                b1 += i;
                else
                b2 += i;
                runs += i;
                if(i%2==1)
                strike++;
                ball ++;
                break;}
            case 8 : {extra+=1;
            runs +=1;
            break;}
            case 9 : {int j;
            printf("how many runs were taken with LB?\n");
            scanf("%d",&j);
            if(j%2==1)
                strike ++;
                extra +=j;
                runs +=j;
                ball ++;
                break;}
            case -1 : {printf("player out, match over.\n");
                printf("score of b1 : %d\n",b1);
                printf("score of b2 : %d\n",b2);
                printf("extra runs given : %d\n",extra );
                printf("total runs : %d\n", runs);
                exit(0);}
    }
    if(ball%6==0){
        over ++ ;
        strike ++;
        printf("over %d is completed \n",over);
        printf("score of b1 : %d\n",b1);
        printf("score of b2 : %d\n",b2);
        printf("extra runs given : %d\n",extra );
        printf("total runs : %d\n", runs);
    }
}
    printf("\nGAME OVER!");
    return 0;
}