#include<stdio.h>
int main()
{
    int x,y;
    int *ptr;
    x=10;
    ptr=&x;
    y=*ptr;
    printf("value of x is=%u\n",x);
    printf("%d is storted at address %u\n",*&x,&x);
    printf("%d is stored at address %u\n",*ptr,ptr);
    printf("%d is stored at address %u\n",*ptr,ptr);
    printf("%d is storeds at addres %u\n",ptr,&ptr);
    printf("%d is stored at address %u\n",y,&y);
    *ptr=25;
    printf("now x=%d\n",x);
    
}
