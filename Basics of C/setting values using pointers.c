#include<stdio.h>
void mytask(int,int,int*,int*,int*);
int main()
{
    int a=10, b=20;
    int sum,product,average;
    mytask(a,b,&sum,&product,&average);
    printf("sum=%d\nproduct=%d\naverage=%d\n",sum,product,average);
}

void mytask(int a,int b,int *x,int *y,int *z)
{
    *x=a+b;
    *y=a*b;
    *z=(a+b)/2;
}
