#include<stdio.h>
void count(int *ptr,int n);
void take(int *ptr,int n);

int main()
{
    int n,arr[50];
    printf("enter the number of elments to be present in the array\n");
    scanf("%d",&n);
    printf("enter the number one by one\n");
    take(arr,n);
    printf("the number of odd numbers in athe array is\n");
    
    count(arr,n);
}

void take(int *ptr,int x){
    int i;
    for(i=0;i<x;i++){
        scanf("%d",(ptr+i));
        
    }
}

void count(int *ptr,int x){
    int count=0,count1=0,i;
    for(i=0;i<x;i++){
        if(*(ptr+i)%2!=0)
        {
            count=count+1;
        }
        else{
            count1=count1+1;
        }
    }
    
    printf("the number of odd numbers are=%d\n,",count);
    printf("the number of even numbers are=%d\n",count1);
}
