#include<stdio.h>
#include<stdlib.h>

void insert(int arr[],int n, int ele, int pos){
    arr[n] = 0;
    int i =0;
    while(n-i > pos){
        arr[n-i] = arr[n-1-i];
        i++;
    }
    arr[pos] = ele;
    return;
}

void delete(int arr[], int n, int pos){
    int i=pos;
    while(i<n){
        arr[i] = arr[i+1];
        i++;
    }
    return;
}

void traverse(int arr[], int n, int pos){
    printf("element = %d\n",arr[pos]);
    return;

}

int main(){

    int arr[1000];
    int n;
    printf("Enter n :\n");
    scanf("%d",&n);

    if(n<0 || n>1000){
        printf("enter correct value of n.\n");
        exit(0);
    }

    printf("enter elements:\n");
    for(int i=0; i<n; i++)
    scanf("%d",&arr[i]);

    int c;
    while(1){
        printf("what do you want to do?\n");
        printf("1. Insert 2. Delete 3. Traverse 4. Exit\n");
        scanf("%d",&c);

        switch(c){
            case(1) :{ printf("enter element and position :\n");
                    int ele,pos;
                    scanf("%d%d",&ele,&pos);
                    insert(arr,n,ele,pos);
                    n++;
                    for(int i=0; i<n; i++)
                    printf("%d ", arr[i]);
                    printf("\n");
                    break;}
            case(2) : { printf("enter position of element you want to delete :\n");
                    int pos;
                    scanf("%d",&pos);
                    delete(arr,n,pos);
                    n--;
                    for(int i=0; i<n; i++)
                    printf("%d ", arr[i]);
                    printf("\n");
                    break;}
            case(3) : { printf("enter position of element you want to print :\n");
                        int pos;
                        scanf("%d",&pos);
                        traverse(arr,n,pos);
                        break;}
            case(4) : {printf("End of code.\n");
                        exit(0);}
        }
    }

    return 0;


}