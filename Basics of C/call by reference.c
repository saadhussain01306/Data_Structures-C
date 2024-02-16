#include<stdio.h>
void swap(int *a,int *b);
int main()
{
    int *p1,*p2,a=10,b=20;
    p1=&a;
    p2=&b;
    printf("before swaping a=%d & b=%d\n",a,b );
    swap(&a,&b);
    printf("after swap a=%d & b=%d\n",*p1,*p2);
    
}
void swap(int *x,int *y)//call by refrence
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
    
}
