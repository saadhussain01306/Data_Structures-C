#include<stdio.h>
void take(int *ptr,int n);
void reverse(int *ptr,int n);

int main()
{
    int n,a[20];
    printf("enter the number of elemnt to be prsent in the array\n");
    scanf("%d",&n);
    printf("enter th elements one by one\n");
    take(a,n);
    printf("the reverse array\n");
    reverse(a,n);
}
void take(int *ptr,int x){
    int i;

    for(i=0;i<x;i++){
        scanf("%d",(ptr+i));
    }
}

void reverse(int *ptr,int x){
    int i;
    for(i=(x-1);i>=0;i--){
        printf("%d\t",*(ptr+i));
    }
}
