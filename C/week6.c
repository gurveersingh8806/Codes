#include<stdio.h>

int main(){
    
    int pm,exp,cis,wm,rsrc;

    printf("enter post graduation marks, research experience, cisco certification(1 if yes), written test marks, finalised research topic(1 if decided) one by one :\n");
    scanf("%d%d%d%d%d",&pm,&exp,&cis,&wm,&rsrc);

    int s;
    printf("are you NET qualified?(yes=1,no=0) \n");
    scanf("%d",&s);

    int date, month, year;
    printf("enter DOB in DD/MM/YYYY format:\n");
    scanf("%d/%d/%d",&date, &month, &year);

    int age = 2025 - year;
    int adjust = (3 < month) + ( month == 3)*(1<date);
    age = age - adjust;



if((pm>=60) && (age<=30 && age>=18) && (exp>=3) && (cis==1) && (wm>=55) && (rsrc==1))
printf("Fellowship is granted");
else if((pm>=60) && (age<=30 && age>=18) && (exp>=3) && (cis!=1) && (wm>=55) && (rsrc==1))
printf("Refer to Dean Academic");
else if((pm>=60) && (age<=30 && age>=18) && (exp<3) && (cis==1) && (wm>=55) && (rsrc==1) && (s==1))
printf("Fellowship is granted");
else if((pm>=55) && (age<=30 && age>=18) && (exp>=3) && (cis==1) && (wm>=55) && (rsrc==1))
printf("You are under waitlist");
else if ((pm>=60) && (age<=30 && age>=18) && (exp>=3) && (cis==1) && (wm>=50) && (rsrc==1))
printf("Refer to Chairman");
else
printf("Fellowship is not Granted");


    return 0;
}